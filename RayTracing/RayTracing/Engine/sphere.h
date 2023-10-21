//
//  sphere.h
//  RayTracing
//
//  Created by Aleksandr Borodulin on 20.10.2023.
//

#ifndef sphere_h
#define sphere_h

#include "hittable.h"
#include "vec3.h"

class sphere: public hittable {
public:
    sphere(point3 _center, double _radius) : center(_center), radius(_radius) {}

    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
        vec3 oc = r.origin() - center;
        auto a = r.direction().length_squared();
        auto half_b = dot(oc, r.direction());
        auto c = oc.length_squared() - radius*radius;

        auto discriminant = half_b*half_b - a*c;
        if (discriminant < 0) return false;
        auto sqrt = sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        auto root = (-half_b - sqrt) / a;
        if (root <= ray_tmin || ray_tmax <= root) {
            root = (-half_b + sqrt) / a;
            if (root <= ray_tmin || ray_tmax <= root)
                return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        rec.normal = (rec.p - center) / radius;

        return true;
    }

private:
    point3 center;
    double radius;
};

#endif /* sphere_h */
