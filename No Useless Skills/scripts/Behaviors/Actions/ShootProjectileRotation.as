class ShootProjectileRotation : ShootProjectile
{
	float m_rotation;

	ShootProjectileRotation(UnitPtr unit, SValue& params)
	{
		super(unit,params);
		m_rotation = GetParamFloat(unit, params, "rotation", false, 0) * PI / 180.0;		
	}	
	
	vec2 GetShootDir(vec2 dir, int i, bool allowRandom) override
	{
		if (allowRandom && (m_spread > 0 || m_spreadMin > 0))
		{
			float rnd = (randf() - 0.5) * (m_spread - m_spreadMin);
			if (m_spreadMin > 0)
				rnd += (randi(2) == 0 ? m_spreadMin : -m_spreadMin);

			float ang = atan(dir.y, dir.x) + rnd + m_rotation;
			return vec2(cos(ang), sin(ang));
		}
		
		float ang = atan(dir.y, dir.x) + m_rotation;
		return vec2(cos(ang), sin(ang));
	}
}