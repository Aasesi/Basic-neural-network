#ifndef CONNECTION_H_
#define CONNECTION_H_
#pragma once
#include <vector>
#include <cstdlib>
/**
 * Connection class.
 * Contains everything connected to weight and calculating new one.
 */
class Connection
{
public:
	/**
	 * Constructor member.
	 * 
	 */
	Connection();
	/**
	 * Returns weight variable.
	 * 
	 * \return weight
	 */
	double use_weight() const;
	/**
	 * Void member.
	 * Calculates new weight.
	 * 
	 * \param deltaa
	 * \param etaa
	 */
	void update_weight(double, double);
	/**
	 * Returns previous weight.
	 * 
	 * \return prevweight.
	 */
	double show_prevweight() const;
private:
	/**
	 * weight.
	 */
	double weight;
	/**
	 * previous weight.
	 */
	double prevweight;
	/**
	 * old delta necessary to update weight.
	 */
	double old_delta;
	/**
	 * Bool that states if weight variable was changed once.
	 */
	bool oncewas = false;
};

#endif
