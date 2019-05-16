#include <Wire.h>                   // Biblioteca de interface I2C
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>                     // Biblioteca Piezo Tone
#include "U8glib.h"
#include <EEPROM.h>

#include <VoltageReference.h>
#include <SimpleKalmanFilter.h>

float measurementConstant = 0.1;
float estimationConstant = 0.1;
float noiseConstant = 0.05;

bool beepOn = false;
bool refAltitudeOn = false;
bool getRefAltitude = false;

SimpleKalmanFilter varioKalmanFilter(measurementConstant, estimationConstant, noiseConstant);
SimpleKalmanFilter altitudeKalmanFilter(measurementConstant, estimationConstant, noiseConstant);

VoltageReference vRef;

#define tone_out1 8
#define tone_out2 9

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);  // Display which does not send AC
Adafruit_BMP280 sensor_bmp;

short speaker_pin1 = 8;                //arduino speaker output -
short speaker_pin2 = 9;                //arduino speaker output +

float vario_down = -2.3;               // Definir a redução
float vario_emergence = -5.1;               // Definir a redução
float vario_up;
float alt[51];
float tim[51];
float beep;
float Beep_period;
float mux = 0.3;
float muxTmp = 0.3;

float Alt = 0.0;                 // Altura zero, no momento da inclusão +!
float vario = 0.0;

float Altitude = 0.0;
float RefAltitude = 0.0; // Reference altitude, will be 0 when device started
float Temperature = 0.0;
unsigned long bounseInput4P = 0UL;
unsigned long time;

unsigned char samples=10;
unsigned char maxsamples=50;
unsigned char countPressVal = 0;
unsigned char tela = 0;
unsigned char menu = 2;
unsigned char memo = 1;


//botão
unsigned char buttonState;
unsigned long duration;
unsigned long resettime;
unsigned char estadobotao=0;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 20; //debounce botão


//relogio
unsigned char relogio=0;
unsigned char segundo = 0, minuto = 0, hora = 0;
unsigned long UtlTime;
unsigned long lastMillis;


//variaveis para  confirmar decolagem
unsigned long temp_alt;
unsigned char temp_verif_alt = 0;
unsigned char ult_altitude;

//variaveis gravação memoria
int num_memo=0;
float Mvarioup=00.0;
float Mvariodown=00.0;
float MaltitudeMax=0000.0;
float MaltitudeDec=0000.0;
float Mganho=0000.0;
float Mpouso=0000.0;
int endfly;
int end_memo=1;
unsigned long gravatempo;
int ler=1;

//variaveis para ler memorias
float Rvarioup=00.0;
float Rvariodown=00.0;
float RaltitudeMax=0000.0;
float Rganho=0000.0;
unsigned char Rhora;
unsigned char Rminuto;
int Rend_memo=1;//ler memoria
int Rend_memo_display=1;
unsigned char Nmeno_display=1;

int  decolagem = 0;
boolean  thermalling = false;

void play_welcome_beep()
{
    if(beepOn)
    {
        for (int aa=100;aa<=800;aa=aa+100)
        {
            tone(tone_out1,aa,400);
            tone(tone_out2,aa+3,400);
            delay(40);
        }
    }
}

const uint8_t rook_bitmap[] PROGMEM = { /* 0X00,0X01,0X80,0X00,0X40,0X00, */
                                        0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X38,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X07,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X00,0X00,0X07,0XFF,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0XFF,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X00,0X01,0XFF,0XFF,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XFF,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X00,0X7F,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X03,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X0F,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X3F,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X00,0X3F,0XFF,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X0F,0XFF,0XFF,0XFF,0XFE,0X7F,0XFF,0XFE,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0XEF,0XFF,0XFF,0XFF,0XFE,0X7F,0XFF,0XFF,0XE0,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0XAF,0XFF,0XFF,0XFF,0XFE,0X7F,0XFF,0XFF,0XF8,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0XAF,0XFF,0XFF,0XFF,0XFE,0X7F,0XFF,0XFF,0XFE,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X7F,0XAF,0XFF,0XFF,0XFF,0XFE,0X7F,0XFF,0XFF,0XFF,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X40,0X2F,0XFF,0XFF,0XFF,0XFE,0X7F,0XFF,0XFF,0XFF,0X80,0X00,0X00,
                                        0X00,0X00,0X00,0X40,0X3F,0XFF,0XFF,0XFF,0XFE,0X7F,0XFF,0XFF,0XFF,0X80,0X00,0X00,
                                        0X00,0X00,0X00,0X7F,0XFF,0XFF,0XE7,0X9F,0XFE,0X7F,0XFF,0XFF,0XFF,0XC0,0X00,0X00,
                                        0X00,0X00,0X00,0X7F,0XFF,0XFF,0X87,0XBF,0XFE,0X7F,0XFF,0XFF,0XFF,0XC0,0X00,0X00,
                                        0X00,0X00,0X00,0X49,0XBF,0XFF,0X87,0XBF,0XFE,0X7F,0XF8,0X0F,0XFF,0XC0,0X00,0X00,
                                        0X00,0X00,0X00,0X49,0XBF,0XFF,0X87,0X3F,0XFE,0X7F,0XF8,0X07,0XFF,0XC0,0X00,0X00,
                                        0X00,0X00,0X00,0X49,0XBF,0XFF,0X87,0X3F,0XFE,0X7F,0XF8,0X03,0XFF,0XC0,0X00,0X00,
                                        0X00,0X00,0X00,0X40,0X3F,0XFF,0X86,0X3F,0XFE,0X7F,0XF8,0X03,0XFF,0XC0,0X00,0X00,
                                        0X00,0X00,0X00,0X40,0X3F,0XFF,0X86,0X3F,0XFE,0X7F,0XF8,0X03,0XFF,0XC0,0X00,0X00,
                                        0X00,0X00,0X00,0X7F,0XFF,0XFF,0X80,0X3F,0XFE,0X7F,0XF8,0X03,0XFF,0XC0,0X00,0X00,
                                        0X00,0X00,0X00,0X7F,0XFF,0XFF,0X80,0X3F,0XFE,0X7F,0XF8,0X07,0XFF,0XC0,0X00,0X00,
                                        0X00,0X00,0X00,0X43,0XFF,0XFF,0X80,0X3F,0XFE,0X7F,0XF8,0X1F,0XFF,0X80,0X00,0X00,
                                        0X00,0X00,0X00,0X60,0X3F,0XFF,0X80,0X3F,0XFE,0X7F,0XFF,0XFF,0XFF,0X80,0X00,0X00,
                                        0X00,0X00,0X00,0X3E,0X3F,0XFF,0X80,0X3F,0XFE,0X7F,0XFF,0XFF,0XFF,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X3C,0X3F,0XFF,0X80,0X3F,0XFE,0X7F,0XFF,0XFF,0XFF,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X40,0X6F,0XFF,0X80,0X3F,0XFE,0X7F,0XFF,0XFF,0XFE,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X47,0XCF,0XFF,0X80,0X3F,0XFE,0X7F,0XFF,0XFF,0XFC,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0XFF,0XEF,0XFF,0X80,0X3F,0XFE,0X7F,0XFF,0XFF,0XF8,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0XEF,0XAF,0XFF,0XFE,0X3F,0XFE,0X7F,0XFF,0XFF,0XE0,0X00,0X00,0X00,
                                        0X00,0X00,0X01,0XC9,0XAF,0XFF,0XFF,0X3F,0XFE,0X7F,0XFF,0XFF,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X01,0XC9,0XA7,0XFF,0XDF,0XFF,0XFE,0X7F,0XFC,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X01,0XC9,0XA7,0XFF,0XFF,0XFF,0XFE,0X7F,0XFC,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X03,0XC0,0X27,0XFF,0XFF,0XFF,0XFC,0X7F,0XFC,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X03,0XC0,0X27,0XFF,0XFF,0XFF,0XFC,0X7F,0XFC,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X01,0XFF,0XE3,0XFF,0XFF,0XFF,0XF8,0X7F,0XFC,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X01,0XE0,0XA1,0XFF,0XFF,0XFF,0XF8,0X7F,0XFC,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0XF0,0XA1,0XFF,0XFF,0XFF,0XF0,0X7F,0XFC,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X7F,0XA0,0XFF,0XFF,0XFF,0XE0,0X7F,0XFC,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X7F,0X20,0X3F,0XFF,0XFF,0XC0,0X7F,0XFC,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X40,0X20,0X1F,0XFF,0XFF,0X00,0X7F,0XFC,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X40,0X20,0X07,0XFF,0XFC,0X00,0X7F,0XFC,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X3F,0XE0,0X0F,0XFF,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X00,0X1F,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X00,0X7F,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X00,0XFE,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X03,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X0F,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X3F,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X01,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X0F,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X70,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                        0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
                                      };




void draw(void) {

    u8g.setColorIndex(1); // Instructs the display to draw with a pixel on.
    u8g.setFont(u8g_font_8x13Br); //para o alfabeto completo com caracteres tirar o r do font_8x13Br
    if(tela == 0){
        u8g.drawBitmapP( 0, 0, 16, 64, rook_bitmap);
    }
    else if(tela == 1){
        u8g.setColorIndex(0);
        u8g.setColorIndex(1);
        u8g.drawStr( 8, 30, "**  LET'S  **"); //acentos http://www.ascii-code.com/
        u8g.drawStr( 37, 50, " FLY  ");
    }

    if(tela == 2){
        u8g.setColorIndex(0);
        u8g.setColorIndex(1);

        unsigned char posVar = 0;
        unsigned char posAlt = 0;
        //temperatura

        u8g.setPrintPos(0, 14);
        u8g.print(Temperature,1);
        u8g.drawStr( 35, 14, "C"); //acentos http://www.ascii-code.com/

        //caixa e m/s vario

        u8g.drawFrame(50,3,78,35); //quadrado vario
        u8g.drawStr(103, 33, "M\057s"); //m/s
        u8g.drawStr(120, 64, "M"); //M altimetro

        //sensibilidade e relogio
        if(relogio==1){
            if(countPressVal != 1 && countPressVal != 0)
            {
                u8g.drawStr(0, 30, "v");
                u8g.setPrintPos(10, 30);
                u8g.print(muxTmp);
            }
            else if(countPressVal == 0)
            {
                u8g.drawStr(0, 30, "Alt1");
            }
            else if(countPressVal == 1)
            {
                u8g.drawStr(0, 30, "Alt2");
            }
        }
        else{
            String timex = "";
            if(hora < 10){
                timex += "0";
            }
            timex += hora;
            if (segundo%2==0)
            {
                timex += ":";
            }
            else{
                timex += " ";
            }
            if(minuto < 10){
                timex += "0";
            }
            timex += minuto;

            u8g.setPrintPos(0, 34);
            u8g.print(timex);

            u8g.setFont(u8g_font_6x13Br);
            u8g.setPrintPos(15, 58);
            u8g.print(mux);
        }


        //altimetro
        if (Altitude >= 1000)
        {
            posAlt = 28;
        }
        else
        {
            posAlt = 48;
        }
        u8g.setFont(u8g_font_fub20n); //se for so numeros usar o n no fim u8g.setFont(u8g_font_fub20n);
        u8g.setPrintPos(posAlt, 64);
        u8g.print(Altitude, 1);

        //vario
        if (vario < 0)
        {
            posVar = 52;
            if(vario < -0.1){
                u8g.drawTriangle(113,15, 122,7, 105,7);
            }
        }
        else
        {
            posVar = 61;
            if(vario > 0.1){
                u8g.drawTriangle(114,6, 124,15, 104,15);
            }
        }
        u8g.setPrintPos(posVar, 30);
        u8g.print(vario,1);


        //bateria
        int vcc = vRef.readVcc();

        u8g.drawFrame(4,42,4,2);
        u8g.drawFrame(2,44,8,18);
        if(vcc > 2600){
            u8g.drawStr( 1, 60, ".");
        }
        if(vcc > 2900){
            u8g.drawStr( 1, 55, ".");
        }
        if(vcc > 3000){
            u8g.drawStr( 1, 50, ".");
        }

        if(!beepOn)
            beepOn = true;
    }

    //-------------------menu-------------
    if(tela == 3){
        u8g.setColorIndex(0);
        u8g.setColorIndex(1);


        //recupera dados da eeprom

        if(Rend_memo_display == 1){ //indica em qual memori o display esta solicitando
            Rend_memo=2;
        }
        if(Rend_memo_display == 2){
            Rend_memo= 22;
        }
        if(Rend_memo_display > 2){
            Rend_memo = (Rend_memo_display*20) + 2;
        }

        if(ler==0){
            EEPROM.get(Rend_memo, Rhora);
            delay(10);
            Rend_memo = Rend_memo +1;
            EEPROM.get(Rend_memo, Rminuto);
            delay(10);
            Rend_memo = Rend_memo + 2;
            EEPROM.get(Rend_memo, Rvarioup);
            delay(10);
            Rend_memo = Rend_memo + 4;
            EEPROM.get(Rend_memo, Rvariodown);
            delay(10);
            Rend_memo = Rend_memo + 4;
            EEPROM.get(Rend_memo, RaltitudeMax);
            delay(10);
            Rend_memo = Rend_memo + 4;
            EEPROM.get(Rend_memo, Rganho);
            delay(10);

            ler=1;
        }

        u8g.drawRFrame(0, 0, 128, 16, 4);
        u8g.setPrintPos(4, 13);
        u8g.print(Nmeno_display);// numero do voo
        u8g.drawStr(20, 13, "MEMORY");

        //Mostra memoria dos voos


        String Rtimex = ""; //organiza a hr do voo
        if(Rhora < 10){
            Rtimex += "0";
        }
        Rtimex += Rhora;
        Rtimex += ":";
        if(Rminuto < 10){
            Rtimex += "0";
        }
        Rtimex += Rminuto;

        u8g.drawStr(45, 13, ".");
        u8g.setPrintPos(80, 13);
        u8g.print(Rtimex); //memoria eeprom aqui
        //u8g.drawStr(22, 31, ":");
        u8g.drawTriangle(10,22, 20,31, 0,31);
        u8g.setPrintPos(26, 31);
        u8g.print(Rvarioup,1); //memoria eeprom aqui
        //u8g.drawStr(82, 31, ":");
        u8g.drawTriangle(70,30, 79,22, 62,22);
        u8g.setPrintPos(82, 31);
        u8g.print(Rvariodown,1); //memoria eeprom aqui
        u8g.drawStr(0, 47, "Alt.Max:");
        u8g.setPrintPos(68, 47);
        u8g.print(RaltitudeMax,1); //memoria eeprom aqui
        u8g.drawStr(0, 64, "Alt.Gain:"); //fazer conta da maxima menos decolagem
        u8g.setPrintPos(71, 64);
        u8g.print(Rganho,1); //memoria eeprom aqui
    }

    if(tela==4){

        u8g.setColorIndex(0);
        u8g.setColorIndex(1);
        u8g.drawStr( 25, 30, "MEMORY");
        u8g.drawStr( 37, 50, "Cleared");

        delay(500);
        menu=5;
    }

    if(tela==5){

        u8g.setColorIndex(0);
        u8g.setColorIndex(1);
        u8g.drawStr( 25, 35, "OK :)");
        delay(500);
        menu=2;

    }


}

void setup()
{
    Serial.begin(9600);// start serial monitor
    Wire.begin();                   // Inicializa i2c
    pinMode(4, INPUT);
    digitalWrite(4, HIGH);
    pinMode(tone_out1, OUTPUT);  // Dinâmica pin8 de saída -
    pinMode(tone_out2, OUTPUT);  // Speaker pin9 saída +
    sensor_bmp.begin(); // Sensibilidade do sensor de pressão
    vRef.begin(); //inicia leitura da voltagem da bateria

    //ler memoria a gravar
    num_memo = EEPROM.read(1); //ultima gravação antes de ser desligado
    delay(10);
    num_memo ++;
    if(num_memo > 20){num_memo = 1;}
    if(num_memo < 1){num_memo = 1;}

    Rend_memo_display = EEPROM.read(1);

    play_welcome_beep();
}


void loop(void)
{
    //oled display
    time = millis() / 300;
    u8g.firstPage();
    // Tempo de calibragem
    if (time <= 5)//start screen
    {
        tela = 0;
    }
    else if(time >5 && time <= 25)//Lets fly screen
    {
        tela = 1;
    }
    else
    {
        tela = menu;

        //--------------salvar dados-----------

        if(vario > Mvarioup){Mvarioup=vario;} //grava na variavel a maior acendente
        if(vario < Mvariodown){Mvariodown=vario;} //grava na variavel a maior descendente

        if(Altitude > MaltitudeMax){
            MaltitudeMax=Altitude;
        }
        //grava na variavel a maior Altitude e ganho comparando com a decolagem

        MaltitudeDec=Altitude;

        if(millis()-temp_alt<0)
        {
            temp_alt=millis();
        }
        else{
            temp_verif_alt=int((millis()-temp_alt)/1000);   // contador de segundos
        }
        if(temp_verif_alt>20 && decolagem==0)
        {
            temp_verif_alt = 0;
            MaltitudeDec=Altitude;

            if((Altitude - ult_altitude < -5.0 || Altitude - ult_altitude > 5.0) && menu == 2){
                decolagem=1;
            }
        }
        ult_altitude = MaltitudeDec;
        Mganho = MaltitudeMax - MaltitudeDec;

        //se depois de 5 segundos a variação de altura nao for maior que 2 metros salva voo na memoria

        if((Mpouso-Altitude < 2 || Mpouso-Altitude > -2) && menu == 2 && endfly==0 && decolagem==1){
            gravatempo = millis();
            endfly=1;
        }

        Mpouso = Altitude;
        if(Mpouso-Altitude < 2 && Mpouso-Altitude > -2 && menu == 2 && endfly==1){
            if (millis() - gravatempo > 5000) {

                //salva a porra toda na eeprom!!!
                EEPROM.write(1, num_memo); //grava o numero da memoria da ultima gravação de voo, para sobrescrever a mais antiga.
                delay(10);

                if(num_memo == 1){ //local para primeira memoria local 2 do eeprom
                    end_memo=2;
                }
                if(num_memo == 2){
                    end_memo= 22;

                }
                if(num_memo > 2){
                    end_memo = (num_memo*20) + 2;
                }

                EEPROM.put(end_memo, hora);
                delay(10);
                end_memo = end_memo + 1;
                EEPROM.put(end_memo, minuto);
                delay(10);
                end_memo = end_memo + 2;

                EEPROM.put(end_memo, Mvarioup);
                delay(10);
                end_memo = end_memo + 4;
                EEPROM.put(end_memo, Mvariodown);
                delay(10);
                end_memo = end_memo + 4;
                EEPROM.put(end_memo, MaltitudeMax);
                delay(10);
                end_memo = end_memo + 4;
                EEPROM.put(end_memo, Mganho);
                delay(10);
                endfly=0;

            }
        }
    }

    int currentState = (digitalRead (4));
    if (currentState != buttonState)
    {
        duration = millis();
        resettime = millis();
    }

    if(currentState ==LOW)
    {
        if ((millis() - duration > 25) && (millis() - duration < 3000)&& menu == 2 && estadobotao==0)
        {
            //Serial.println("long click");
            countPressVal++;
            if(beepOn)
                tone(tone_out1,1800,40);
            delay(80);
            if(countPressVal > 4){countPressVal = 0;}

            //mostra relogio e variaçaõ
            lastMillis = millis();
            relogio = 1;
            estadobotao=1;
        }

        if (millis() - duration > 3000 && menu == 2 && estadobotao==1) {
            //voos gravados
            ler =0;
            menu = 3;
            duration = millis();
        }

        if (millis() - duration > 3000 && menu == 3 && estadobotao==1) {
            //tela vario
            menu = 2;
            Nmeno_display = 1;
            Rend_memo_display = EEPROM.read(1);
            duration = millis();
        }

        //menu configurações
        if (millis() - resettime > 9000 && (menu == 2 || menu == 3) && estadobotao==1) {

            menu=4;

            // grave 0 em todos os 512 bytes da EEPROM
            for (int i = 0; i < 512; i++)
                EEPROM.write(i, 0);
            Nmeno_display = 1;
            Rend_memo_display = EEPROM.read(1);
            resettime = millis();
        }

        if ((millis() - duration >5) && (millis() - duration < 2000)&& menu == 3 && estadobotao==0) {
            ler =0;
            Nmeno_display++; // mostra so o numero do voo
            Rend_memo_display--; //puxa a pemoria de voo da mais rescente pra mais antiga
            if(Rend_memo_display < 1){Rend_memo_display=20;}
            if(Nmeno_display > 20){Nmeno_display=1;}
            estadobotao=1;
        }

    }
    if(currentState ==HIGH){
        estadobotao=0;
    }
    buttonState = currentState;

    // == MENU SENSIBILIDADE PARA LEVANTAR ==

    if((countPressVal) == 0) {refAltitudeOn = false;} // 1 sinal
    if((countPressVal) == 1) {refAltitudeOn = true;} // 2 sinal
    if((countPressVal) == 2) {muxTmp = 0.3;} // 3 sinal
    if((countPressVal) == 3) {muxTmp = 0.5;} // 4 sinal
    if((countPressVal) == 4) {muxTmp = 0.8;} // 5 sinal

    vario_up = mux;

    //mostra relogio e variaçaõ
    if (lastMillis > 0 && (millis() - lastMillis > 3000))
    {
        relogio = 0;
        lastMillis = 0;

        if((countPressVal) == 2) {mux = 0.3;} // 3 sinal
        if((countPressVal) == 3) {mux = 0.5;} // 4 sinal
        if((countPressVal) == 4) {mux = 0.8;} // 5 sinal

        if(countPressVal > 1)
        {
            if(!refAltitudeOn)
            {
                countPressVal = 0;
            }
            else
            {
                countPressVal = 1;
            }
        }
    }

    float tempo = millis();
    float N1=0;
    float N2=0;
    float N3=0;
    float D1=0;
    float D2=0;

    Temperature = (sensor_bmp.readTemperature());
    auto tmpAlt  = (sensor_bmp.readAltitude(1013.25));// calculate altitude

    if(!getRefAltitude)
    {
        RefAltitude = tmpAlt;
        getRefAltitude = true;
    }

    for(int cc=1;cc<=maxsamples;cc++){                                   // averager
        alt[(cc-1)]=alt[cc];
        tim[(cc-1)]=tim[cc];
    };

    alt[maxsamples]=tmpAlt;
    tim[maxsamples]=tempo;
    float stime=tim[maxsamples-samples];
    for(int cc=(maxsamples-samples);cc<maxsamples;cc++){
        N1+=(tim[cc]-stime)*alt[cc];
        N2+=(tim[cc]-stime);
        N3+=(alt[cc]);
        D1+=(tim[cc]-stime)*(tim[cc]-stime);
        D2+=(tim[cc]-stime);
    };

    Altitude = altitudeKalmanFilter.updateEstimate(round(tmpAlt*100)/100.0);   //apply kalman filter

    //Serial.println(RefAltitude);
    if(refAltitudeOn)
    {
        Altitude = Altitude - RefAltitude;
        if(Altitude < 0) Altitude = 0.0;
    }

    auto tmpVario  = 1000.0*(float)((samples*N1)-N2*N3)/(float)(samples*D1-D2*D2); // calculate vario
    vario = varioKalmanFilter.updateEstimate(round(tmpVario*100)/100.0);   //apply kalman filter

    if ((tempo-beep)>Beep_period)
    {
        beep=tempo;
        if (vario>vario_up && vario<15 )
        {
            Beep_period=350-(vario*10);
            if(beepOn)
            {
                tone(tone_out1,(1000+(100*vario)),300-(vario*5)); // Som em ascensão
                tone(tone_out2,(1003+(100*vario)),300-(vario*5));
            }
            thermalling = true;
        }
        else if ((vario < 0 ) && (thermalling == true))
        {
            thermalling = false;
            //tone_out2.play(800, 800); Predpotok // Som (é opcional)
        }
        else if (vario < vario_down && vario > vario_emergence){         // Som a afundar
            Beep_period=200;
            if(beepOn)
            {
                tone(tone_out1,(300-(vario)),340);
                tone(tone_out2,(303-(vario)),340);
            }
            thermalling = false;
        }
        else if (vario < vario_emergence){         // Som emergencia
            Beep_period=200;
            if(beepOn)
            {
                tone(tone_out1,2000,250);
                tone(tone_out2,2003,250);
                delay(200);
                tone(tone_out1,1000,250);
                tone(tone_out2,1003,250);
            }
            thermalling = false;
        }
    }

    //relogio
    if(decolagem==1){ //inicia o cronometro quando detectada a decolagem
        if(millis()-UtlTime<0)
        {
            UtlTime=millis();
        }
        else{
            segundo=int((millis()-UtlTime)/1000);
        }
        if(segundo>59)
        {
            segundo=0;
            minuto++;
            UtlTime=millis();
            if(minuto>59)
            {
                hora++;
                minuto=0;
            }
        }
    }
    else{
        segundo=00;
        minuto=00;
        hora=00;
    }

    //-----------mostrar telas-----------
    do {
        draw();
    } while( u8g.nextPage() );
    //fim oled display
}
