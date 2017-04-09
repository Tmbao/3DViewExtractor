#ifndef VIEW_PROVIDER_EXAMPLE_H_
#define VIEW_PROVIDER_EXAMPLE_H_

#include <cmath>

#include "view_provider.h"


class ViewProviderExample : public ViewProvider {
private:
    void rotate(double &x, double &y, const double &angle) {
        double x_new = x * cos(angle) - y * sin(angle);
        double y_new = x * sin(angle) + y * cos(angle);
        x = x_new;
        y = y_new;
    }

public:
    std::vector<ViewConfiguration> provides() {
        std::vector<ViewConfiguration> views;

        // Take top and bottom
        views.push_back(ViewConfiguration(
            CameraPosition(0, 2, 0, 0, 0, 0, -1, 2, 0),
            "A"));
        views.push_back(ViewConfiguration(
            CameraPosition(0, -2, 0, 0, 0, 0, 1, -2, 0),
            "Z"));

        // Rotate around
        // We will rotate the point by 45 deg each step
        double delta = M_PI / 4;
        std::string name = "A";
        for (int step = 0; step < 8; ++step) {
            // Starting point
            double pos_x = 2, pos_y = 0, pos_z = 0; 
            double up_x = 2, up_y = 1, up_z = 0;

            rotate(pos_x, pos_z, step * delta);
            rotate(up_x, up_z, step * delta);
            ++name[0];
            views.push_back(ViewConfiguration(
                CameraPosition(pos_x, pos_y, pos_z, 0, 0, 0, up_x - pos_x, up_y - pos_y, up_z - pos_z),
                name));
        }
        for (int step = 0; step < 8; ++step) {
            // Starting point
            double pos_x = 2, pos_y = 0, pos_z = 0; 
            double up_x = 2, up_y = 1, up_z = 0;

            // Go up
            rotate(pos_x, pos_y, delta);
            rotate(up_x, up_y, delta);

            rotate(pos_x, pos_z, step * delta);
            rotate(up_x, up_z, step * delta);
            ++name[0];
            views.push_back(ViewConfiguration(
                CameraPosition(pos_x, pos_y, pos_z, 0, 0, 0, up_x - pos_x, up_y - pos_y, up_z - pos_z),
                name));
        }
        for (int step = 0; step < 8; ++step) {
            // Starting point
            double pos_x = 2, pos_y = 0, pos_z = 0;
            double up_x = 2, up_y = 1, up_z = 0;

            // Go down
            rotate(pos_x, pos_y, -delta);
            rotate(up_x, up_y, -delta);

            rotate(pos_x, pos_z, step * delta);
            rotate(up_x, up_z, step * delta);
            ++name[0];
            views.push_back(ViewConfiguration(
                CameraPosition(pos_x, pos_y, pos_z, 0, 0, 0, up_x - pos_x, up_y - pos_y, up_z - pos_z),
                name));
        }

        return views;
    }
};

#endif
