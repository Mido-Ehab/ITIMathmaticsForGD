

class Bounce {

public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="t">time</param>
	/// <param name="b">start</param>
	/// <param name="c">change</param>
	/// <param name="d">duration</param>
	/// <returns></returns>
	static float easeIn(float t, float b, float c, float d) {
		return c - easeOut(d - t, 0, c, d) + b;
	}
	/// <summary>
	/// 
	/// </summary>
	/// <param name="t">time</param>
	/// <param name="b">start</param>
	/// <param name="c">change</param>
	/// <param name="d">duration</param>
	/// <returns></returns>
	static float easeOut(float t, float b, float c, float d) {
		if ((t /= d) < (1 / 2.75f)) {
			return c * (7.5625f * t * t) + b;
		}
		else if (t < (2 / 2.75f)) {
			float postFix = t -= (1.5f / 2.75f);
			return c * (7.5625f * (postFix)*t + .75f) + b;
		}
		else if (t < (2.5 / 2.75)) {
			float postFix = t -= (2.25f / 2.75f);
			return c * (7.5625f * (postFix)*t + .9375f) + b;
		}
		else {
			float postFix = t -= (2.625f / 2.75f);
			return c * (7.5625f * (postFix)*t + .984375f) + b;
		}
	}
	/// <summary>
	/// 
	/// </summary>
	/// <param name="t">time</param>
	/// <param name="b">start</param>
	/// <param name="c">change</param>
	/// <param name="d">duration</param>
	/// <returns></returns>
	static float easeInOut(float t, float b, float c, float d) {
		if (t < d / 2) return easeIn(t * 2, 0, c, d) * .5f + b;
		else return easeOut(t * 2 - d, 0, c, d) * .5f + c * .5f + b;
	}
};

