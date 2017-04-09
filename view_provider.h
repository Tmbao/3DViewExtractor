#ifndef VIEW_PROVIDER_H_
#define VIEW_PROVIDER_H_

#include <vector>

#include "camera_position.h"


struct ViewConfiguration {
    CameraPosition cam_pos;
    std::string view_name;

    ViewConfiguration(const CameraPosition &cam_pos, const std::string &view_name):
        cam_pos(cam_pos), view_name(view_name) {       
    }
};

class ViewProvider {
public:
    virtual std::vector<ViewConfiguration> provides() = 0;
};

#endif
