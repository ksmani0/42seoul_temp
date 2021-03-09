/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:09:23 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/09 19:09:26 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
**Finally, according to the equation extracted by the triangular determinant,
**the intersection point p (a parameter that determines
**whether it is inside or outside the triangle) is secured.
*/
double	get_p_parameter(t_triangle *trngl, t_vec3 p0)
{
	double p;

	if (trngl->equa == 0)
		p = (trngl->e1.y * p0.x - trngl->e1.x * p0.y) / trngl->det;
	else if (trngl->equa == 1)
		p = (trngl->e1.z * p0.y - trngl->e1.y * p0.z) / trngl->det;
	else
		p = (trngl->e1.z * p0.x - trngl->e1.x * p0.z) / trngl->det;
	return (p);
}

/*
**Obtaining the intersection point q (a parameter that determines
**whether it is inside or outside the triangle)
**according to the equation extracted from the triangle determinant
*/
double	get_q_parameter(t_triangle *trngl, t_vec3 p0)
{
	double q;

	if (trngl->equa == 0)
		q = (trngl->e0.x * p0.y - trngl->e0.y * p0.x) / trngl->det;
	else if (trngl->equa == 1)
		q = (trngl->e0.y * p0.z - trngl->e0.z * p0.y) / trngl->det;
	else
		q = (trngl->e0.x * p0.z - trngl->e0.z * p0.x) / trngl->det;
	return (q);
}

