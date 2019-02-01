
// Basic graph drawing just to help a bit....
void Analytics::ShowGraph(std::list<int> &numberList, int yUnits /* = 100 */)
{
	if (numberList.size() <= 1)
		return;

	int max=0, min = 0;
	for (std::list<int>::iterator it = numberList.begin(); it != numberList.end(); it ++)
	{
		//std::cout << *it << " ";
		if (*it < min) min = *it;
		if (*it > max) max = *it;
	}
	//****** Trade Trend a - counter weighting ******  Num files [21] iterations per file [11] total iterations [231]
	//Params XXX_09_05_2010_091419( -3600, 32165, -75, 115, 1.00000000000000, 2.46256426539900, 0.06715771395367, 0.30165733009775, 1.19799040180600, 0.50000000000000, 0.13087402447200, 0.05894242594700, 9, 0.20000000000000, 360, 7000, 7400, 250, 0.05338675135300, 0.00614663947260, 26, 500);
	//  PnL [+2251/+107] Losing Days [4/21 19%] Trades/day [9] Tested [09/05/2010] Time [3:26]
	//   |:
	//   |:
	//   |:  .
	//   |:  :     :
	//   |:  :     :  . .
	//   |: ::. .  : .: :    .
	//   |:::::.:_::.::_:__._:_
	//   |             : :: :
	//   |             ' '' :
	int positiveIterations = (max/UNITS); // might be 4
	int negativeIterations = (min/UNITS) - 1; // might be -3
	for (int i = positiveIterations; i >= negativeIterations; i--)
	{
		if (i == 4)
			std::cout << " //   500 | ";
		else if ((i == 9))
			std::cout << " //  1000 | ";
		else if ((i == 19))
			std::cout << " //  2000 | ";
		else if ((i == 29))
			std::cout << " //  3000 | ";
		else if ((i == 39))
			std::cout << " //  4000 | ";
		else if ((i == 49))
			std::cout << " //  5000 | ";
		else if ((i == 59))
			std::cout << " //  6000 | ";
		else if ((i == 69))
			std::cout << " //  7000 | ";
		else if ((i == 79))
			std::cout << " //  8000 | ";
		else if ((i == 89))
			std::cout << " //  9000 | ";
		else if ((i == 99))
			std::cout << " // 10000 | ";
		else if ((i == -5))
			std::cout << " //  -500 | ";
		else if ((i == -10))
			std::cout << " // -1000 | ";
		else if ((i == -20))
			std::cout << " // -2000 | ";
		else if ((i == -30))
			std::cout << " // -3000 | ";
		else if ((i == -40))
			std::cout << " // -4000 | ";
		else if ((i == -50))
			std::cout << " // -5000 | ";
		else if ((i == -60))
			std::cout << " // -6000 | ";
		else if ((i == -70))
			std::cout << " // -7000 | ";
		else if ((i ==  0))
			std::cout << " //     0 | ";
		else
			std::cout << " //       | ";


		for (std::list<int>::iterator it = numberList.begin(); it != numberList.end(); it ++)
		{
			char spaceChar = ' ';
			if (i == 0) spaceChar = '_';
			int val = *it;
			int hundreds = val / UNITS;
			if (i >= 0) { // we're still doing the upper band
				if (val > 0) {
					if (hundreds >= i ) { // i.e. 4 > 3 top line
						if ( val >= ((i * UNITS) + (UNITS/2) ))
							std::cout << ":";
						else
							std::cout << ".";
					} else {
						std::cout << spaceChar;
					}
				} else {
					std::cout << spaceChar;
				}
			} else { // we're still doing the upper band
				if (val < 0) {
					if ((i+1) >= hundreds) {
						if ( val < (((i+1) * UNITS) - (UNITS/2)) )
							std::cout << ":";
						else
							std::cout << "'";
					} else {
						std::cout << " ";
					}
				} else {
					std::cout << " ";
				}
			}
		}
		if (i == positiveIterations)
			std::cout << " [" << max << "]";
		if (i == negativeIterations)
			std::cout << " [" << min << "]";
		std::cout << std::endl;
	}

	std::cout << std::endl;

}

