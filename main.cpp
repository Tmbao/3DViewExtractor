#include <algorithm>
#include <stdexcept>

#include <pcl/io/obj_io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/PolygonMesh.h>

#include "camera_position.h"
#include "off_helpers.h"
#include "utils.h"
#include "view_extractor.h"
#include "view_provider_example.h"

pcl::PolygonMesh load(const std::string &path) {
    auto ext = get_extension(path);
    std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

    pcl::PolygonMesh mesh;

    if (ext == "obj") {
        pcl::io::loadOBJFile(path, mesh);
    } else if (ext == "off") {
        loadOFFFile(path, mesh);
    } else if (ext == "pcd") {
        pcl::io::loadOBJFile(path, mesh);
    } else if (ext == "ply") {
        pcl::io::loadPLYFile(path, mesh);
    } else {
        throw std::invalid_argument("Invalid file");
    }

    return mesh;
}


int main(int argc, char const *argv[])
{
    if (argc == 2) {
        auto mesh = load(argv[1]);
        std::string prefix, _;
        split_path(argv[1], prefix, _);
        extract_view(mesh, new ViewProviderExample(), prefix);
        return 0;
    } else {
        cerr << "Invalid argument" << endl;
        return 1;
    }
}
