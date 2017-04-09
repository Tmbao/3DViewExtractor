#ifndef CAMERA_POSITION_H_
#define CAMERA_POSITION_H_

struct CameraPosition {
    double pos_x, pos_y, pos_z, view_x, view_y, view_z, up_x, up_y, up_z;

    CameraPosition(
        double pos_x, double pos_y, double pos_z, 
        double view_x, double view_y, double view_z, 
        double up_x, double up_y, double up_z) :
            pos_x(pos_x), pos_y(pos_y), pos_z(pos_z),
            view_x(view_x), view_y(view_y), view_z(view_z),
            up_x(up_x), up_y(up_y), up_z(up_z) {
    }
};

#endif
