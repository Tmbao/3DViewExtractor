#ifndef VIEW_EXTRACTOR_H_
#define VIEW_EXTRACTOR_H_

#include <pcl/PolygonMesh.h>
#include <pcl/visualization/pcl_visualizer.h>

#include "utils.h"
#include "view_provider.h"


void extract_view(const pcl::PolygonMesh &mesh, ViewProvider* view_provider, const std::string &path) {
    for (auto view_conf : view_provider->provides()) {
        auto viewer = new pcl::visualization::PCLVisualizer("Viewer"); 
        viewer->addPolygonMesh(mesh);
        viewer->setSize(320, 240);
        viewer->setShowFPS(false);
        viewer->setCameraPosition(
            view_conf.cam_pos.pos_x, view_conf.cam_pos.pos_y, view_conf.cam_pos.pos_z,
            view_conf.cam_pos.view_x, view_conf.cam_pos.view_y, view_conf.cam_pos.view_z,
            view_conf.cam_pos.up_x, view_conf.cam_pos.up_y, view_conf.cam_pos.up_z);
        viewer->saveScreenshot(join_path(path, view_conf.view_name + ".jpg"));
        viewer->close();
    }
}

#endif
