//
//  hittable.h
//  RayTracing
//
//  Created by Aleksandr Borodulin on 20.10.2023.
//

#ifndef hittable_h
#define hittable_h

#include "ray.h"

class hit_record {
public:
    point3 p;
    vec3 normal;
    double t;
};

class hittable {
public:
    virtual ~hittable() = default;

    virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};

#endif /* hittable_h */
