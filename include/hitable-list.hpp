#pragma once

#include <vector>
#include <memory>

#include "hitable.hpp"


using HitableListType = std::vector<std::shared_ptr<Hitable>>;


class HitableList : public Hitable {
public:

	HitableList() {}
	HitableList(HitableListType& list) : list{ list } {}
	virtual bool Hit(const Ray& r, Scalar t_min, Scalar t_max, HitRecord& record) const override;

	HitableListType list;
};

bool HitableList::Hit(const Ray& r, Scalar t_min, Scalar t_max, HitRecord& record) const {
	HitRecord temp_record;
	bool hit_anything = false;
	float64_t closest_so_far = t_max;
	for(std::size_t i = 0; i < this->list.size(); ++i) {
		if(list[i]->Hit(r, t_min, closest_so_far, temp_record)) {
			hit_anything = true;
			closest_so_far = temp_record.t;
			record = temp_record;
		}
	}
	return hit_anything;
}
