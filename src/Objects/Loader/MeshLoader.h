#include <Objects/MeshObject.h>
#include <tiny_obj_loader.h>
#include <boost/log/trivial.hpp>
//
// Created by michaelpollind on 1/16/17.
//

#ifndef _MESHLOADER_H
#define _MESHLOADER_H


MeshObject* LoadObj(const char *path, int& size)
{
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string err;
    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &err,path);

    if (!err.empty()) { // `err` may contain warning message.
    //    std::cerr << err << std::endl;

        BOOST_LOG_TRIVIAL(trace) << err;

    }

    if (!ret) {
        exit(1);
    }



// Loop over shapes
    for (size_t s = 0; s < shapes.size(); s++) {
        // Loop over faces(polygon)
        size_t index_offset = 0;
        for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
            int fv = shapes[s].mesh.num_face_vertices[f];

            VertexNormal* vn = new VertexNormal[fv];
            GLushort* indecies = new GLushort[shapes[s].mesh.indices.size()];
            // Loop over vertices in the face.
            for (size_t v = 0; v < fv; v++) {
                // access to vertex
                tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
                indecies[v] = shapes[s].mesh.indices[index_offset+v].vertex_index;

                vn[idx.vertex_index/3].vx = attrib.vertices[3*idx.vertex_index+0];
                vn[idx.vertex_index/3].vy = attrib.vertices[3*idx.vertex_index+1];
                vn[idx.vertex_index/3].vz = attrib.vertices[3*idx.vertex_index+2];

                vn[idx.vertex_index/3].vx = attrib.vertices[3*idx.normal_index+0];
                vn[idx.vertex_index/3].vy = attrib.vertices[3*idx.normal_index+1];
                vn[idx.vertex_index/3].vz = attrib.vertices[3*idx.normal_index+2];



                /*float vx = attrib.vertices[3*idx.vertex_index+0];
                float vy = attrib.vertices[3*idx.vertex_index+1];
                float vz = attrib.vertices[3*idx.vertex_index+2];
                float nx = attrib.normals[3*idx.normal_index+0];
                float ny = attrib.normals[3*idx.normal_index+1];
                float nz = attrib.normals[3*idx.normal_index+2];
                float tx = attrib.texcoords[2*idx.texcoord_index+0];
                float ty = attrib.texcoords[2*idx.texcoord_index+1];*/
            }

            return new MeshObject(vn,fv,indecies,shapes[s].mesh.indices.size());
            index_offset += fv;

            // per-face material
            shapes[s].mesh.material_ids[f];
        }
    }


}


#endif
