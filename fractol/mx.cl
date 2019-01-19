static double my_abs(double a)
{
	if (a < 0)
		a = (double)a * -1;
	return (a);
}

static void take_colour(
	int color,
	int counter,
	int max_iter,
	unsigned char *r,
	unsigned char *g,
	unsigned char *b)
{
	if (counter == max_iter)
	{
		*r = 0;
		*g = 0;
		*b = 0;
	}
	else if (color == 1)
	{
		counter = counter % 7;
		if (counter == 0)
		{
			*r = 66;
			*g = 30;
			*b = 15;
		}
		else if (counter == 1)
		{
			*r = 25;
			*g = 7;
			*b = 26;
		}
		else if (counter == 2)
		{
			*r = 12;
			*g = 44;
			*b = 138;
		}
		if (counter == 3)
		{
			*r = 211;
			*g = 236;
			*b = 248;
		}
		else if (counter == 4)
		{
			*r = 248;
			*g = 201;
			*b = 95;
		}
		else if (counter == 5)
		{
			*r = 153;
			*g = 87;
			*b = 0;
		}
		else if (counter == 6)
		{
			*r = 176;
			*g = 10;
			*b = 10;
		}
	}
	else if (color == 2)
	{
		*r = ((counter % 16 + 1) * 16 + 1);
		*g = 0;
		*b = 0;
	}
	else
	{
		*r = 0;
		*g = 0;
		*b = (counter * 16) % 255;
	}
}

 __kernel void iterate(
	__global char *output,
	double center_x,
	double center_y,
	double bound,
	double step,
	int frac,
	int map_x,
	int map_y,
	int max_iter,
	int color,
	double jul_po_x,
	double jul_po_y)
{
	double start_x, start_y;
	int counter = 0, id, col;
	double x, y, aa;
	unsigned char r, g, b;

	id = get_global_id(0);
	if (id < 0 || id >= map_x * map_y)
		return ;
	start_x = center_x - bound + step * (id % map_x);
	start_y = center_y - bound + step * (id / map_x);
	if (frac == 1)
	{
		int accur = 4;
		x = start_x;
		y = start_y;
		while (counter < max_iter)
		{
			aa = x * x - y * y;
			y = 2 * x * y + start_y;
			x = aa + start_x;
			if (x * x + y * y > accur)
				break ;
			counter++;
		}
		take_colour(color, counter, max_iter, &r, &g, &b);
	}
	else if (frac == 2)
	{
		while (counter < max_iter)
		{
			int accur = 4;
			x = start_x;
			y = start_y;
			start_x = x * x - y * y + jul_po_x;
			start_y = 2 * x * y + jul_po_y;
			if (x * x + y * y > accur)
				break ;
			counter++;
		}
		take_colour(color, counter, max_iter, &r, &g, &b);
	}
	else if (frac == 3)
	{
		int accur = 4;
		x = start_x;
		y = start_y;
		while (counter < max_iter)
		{
			aa = x * x -  y * y;
			y = my_abs(2 * x * y) + start_y;
			x = my_abs(aa + start_x);
			if (x * x + y * y > accur)
				break ;
			counter++;
		}
		take_colour(color, counter, max_iter, &r, &g, &b);
	}
	else if (frac == 4)
	{
		int accur = 4;
		x = start_x;
		y = start_y;
		while (counter < max_iter)
		{
			aa = x * x - y * y + start_x;
			y = -2 * x * y + start_y;
			x = aa;
			if (x * x + y * y > accur)
				break ;
			counter++;
		}
		take_colour(color, counter, max_iter, &r, &g, &b);
	}
	col = r * 256 * 256 + g * 256 + b;
	((__global unsigned int *)output)[id] = col;
}