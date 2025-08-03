class ShootProjectileRotationFan : ShootProjectileRotation
{
	float m_jitter;
	
	ShootProjectileRotationFan(UnitPtr unit, SValue& params)
	{
		super(unit, params);
		
		m_jitter = GetParamFloat(unit, params, "jitter", false, 0);
	}

	vec2 GetShootDir(vec2 dir, int i, bool allowRandom) override
	{
		if ((m_spread > 0 || m_spreadMin > 0) && m_projectiles > 1)
		{
			float step = m_spread / (m_projectiles - 1);
			float ang = atan(dir.y, dir.x) - m_spread / 2.0 + i * step + m_rotation;
			
			if (allowRandom && m_jitter > 0)
				ang += (randf() - 0.5) * m_jitter * step;
			
			return vec2(cos(ang), sin(ang));
		}
		
		float ang = atan(dir.y, dir.x) + m_rotation;
		return vec2(cos(ang), sin(ang));
	}
}