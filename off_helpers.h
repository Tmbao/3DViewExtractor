#ifndef OFF_HELPERS_H_
#define OFF_HELPERS_H_

#include <fstream>

#include <pcl/common/io.h>
#include <pcl/PolygonMesh.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>


pcl::PolygonMesh load_off(const std::string& path) {
    pcl::PolygonMesh mesh;

    std::ifstream ifs(path, std::ifstream::in);

    // Ignore the first line
    ifs.ignore(4);

    // Read the mesh size
    size_t n_vertices, n_faces, _;
    ifs >> n_vertices >> n_faces >> _;

    // Read vertices
    pcl::PointCloud<pcl::PointXYZ> vertices;
    for (size_t i = 0; i < n_vertices; ++i) {
        float x, y, z;
        ifs >> x >> y >> z;
        vertices.push_back(pcl::PointXYZ(x, y, z));
    }
    pcl::toPCLPointCloud2(vertices, mesh.cloud);

    // Read faces
    for (size_t i = 0; i < n_faces; ++i) {
        pcl::Vertices face;
        size_t size;
        ifs >> size;
        for (size_t j = 0; j < size; ++j) {
            uint32_t vid;
            ifs >> vid;
            face.vertices.push_back(vid);
        }
        mesh.polygons.push_back(face);
    }

    ifs.close();

    return mesh;
}

#endif
