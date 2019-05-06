#ifndef VIEW_H
#define VIEW_H
#include "libraries.h"
#pragma once
#include <iostream>
#include "model.h"
// View is responsible to present data to users
class View {
    public:
        View(const Model &model) {
            this->model = model;
        }
        View() {}
        void SetModel(const Model &model) {
            this->model = model;
        }
        void Render() {
            std::cout << "Model Data = " << model.Data() << endl;
        }
    private:
        Model model;
};

#endif // VIEW_H
