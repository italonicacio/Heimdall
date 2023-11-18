#pragma once

#include <vector>
#include <memory>

#include "hitable.hpp"

template<typename T>
using HitableListType = std::vector<std::shared_ptr<Hitable<T>>>;


template<typename T>
class HitableList : public Hitable<T> {
	static_assert(std::is_same<T, float32_t>::value || std::is_same<T, float64_t>::value,
		"Template argument must be float32_t or float64_t");
public:

	HitableList() {}
	HitableList(HitableListType<T>& list) : list{ list } {}
	virtual bool Hit(const Ray<T>& r, T t_min, T t_max, HitRecord<T>& record) const override;

	HitableListType<T> list;
};

template<typename T>
bool HitableList<T>::Hit(const Ray<T>& r, T t_min, T t_max, HitRecord<T>& record) const {
	HitRecord<T> temp_record;
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
