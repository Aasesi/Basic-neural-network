#include "Connection.h"

/**
 * Constructor.
 * Randomizes weight.
 * Weight value is between 0.0 and 1.0
 * 
 */
Connection::Connection()
{
	weight = (rand() / double(RAND_MAX));
}
/**
 * Shows weight.
 * 
 * \return weight
 */
double Connection::use_weight() const
{
	return weight;
}
/**
 * Calculations to update weight and set previousweight, old_delta and change bool oncewas.
 * 
 * \param deltaa
 * \param etaa
 */
void Connection::update_weight(double deltaa, double etaa)
{
	if (oncewas == false)
	{
		prevweight = weight;
		weight = weight - deltaa * etaa + 0.5 * (deltaa);
		oncewas == true;
		old_delta = deltaa;
	}
	else
	{
		prevweight = weight;
		weight = weight - deltaa * etaa + 0.5 * (old_delta);
		old_delta = deltaa;
	}
}
/**
 * Shows previous weight.
 * 
 * \return prevweight
 */
double Connection::show_prevweight() const
{
	return prevweight;
}