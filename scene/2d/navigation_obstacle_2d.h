/*************************************************************************/
/*  navigation_obstacle_2d.h                                             */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef NAVIGATION_OBSTACLE_2D_H
#define NAVIGATION_OBSTACLE_2D_H

#include "scene/2d/node_2d.h"
#include "scene/main/node.h"

class NavigationObstacle2D : public Node {
	GDCLASS(NavigationObstacle2D, Node);

	Node2D *parent_node2d = nullptr;

	RID agent;
	RID map_before_pause;
	RID map_override;

	bool estimate_radius = true;
	real_t radius = 1.0;

protected:
	static void _bind_methods();
	void _validate_property(PropertyInfo &p_property) const;
	void _notification(int p_what);

public:
	NavigationObstacle2D();
	virtual ~NavigationObstacle2D();

	RID get_rid() const {
		return agent;
	}

	void set_agent_parent(Node *p_agent_parent);

	void set_navigation_map(RID p_navigation_map);
	RID get_navigation_map() const;

	void set_estimate_radius(bool p_estimate_radius);
	bool is_radius_estimated() const {
		return estimate_radius;
	}
	void set_radius(real_t p_radius);
	real_t get_radius() const {
		return radius;
	}

	TypedArray<String> get_configuration_warnings() const override;

private:
	void initialize_agent();
	void reevaluate_agent_radius();
	real_t estimate_agent_radius() const;
};

#endif // NAVIGATION_OBSTACLE_2D_H
