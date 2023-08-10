/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guides.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:46:35 by mnoguera          #+#    #+#             */
/*   Updated: 2023/08/10 15:09:10 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			events_guide(void)
{
    write(1, "CONTROLERS:\n", 13);
    write(1, "  esc -> close the window and end the program\n", 47);
    write(1, "  + -> increase iterations\n", 28);
    write(1, "  - -> decrease iterations\n", 28);
    write(1, "  arrows -> move view\n", 23);
    write(1, "  enter -> zoom in centered\n", 29);
    write(1, "  space -> zoom out centered\n", 30);
    write(1, "  tab -> change colors palette\n", 32);
}

int			fractals_guide(void)
{
    write(1, "FRACTALS:\n", 11);
    return (0);
}

int general_guide(void)
{
    fractals_guide();
    events_guide();
    return (0);
}
