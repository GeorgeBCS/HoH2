namespace Modifiers
{
	class StatConvert : StatModifier
	{
		ConvertableStat m_orig_stat;
		ConvertableStat m_mod_stat;
		vec2 m_mul;
		
		StatConvert(UnitPtr unit, SValue& params)
		{
			super(unit, params);
			
			m_orig_stat = ParseStat(GetParamString(unit, params, "originatingStat", true));
			m_mod_stat = ParseStat(GetParamString(unit, params, "modifiedStat", true));
			m_mul = GetParamVec2(unit, params, "mul", true);
			
			Ordering = int(ModifierOrdering::Post) + 20;
		}
		
		void Modify(PlayerRecord@ player, PlayerStats@ stats, float intensity) override
		{
			float statToAdd = 1.0f;
			
			if(m_orig_stat!=m_mod_stat)
			{
				switch (m_orig_stat)
				{
				case ConvertableStat::IceDamageMul:
					statToAdd = max(0, stats.IceDamageMul - 1.0f);
					break;
				case ConvertableStat::LightningDamageMul:
					statToAdd = max(0, stats.LightningDamageMul - 1.0f);
					break;
				case ConvertableStat::PoisonDamageMul:
					statToAdd = max(0, stats.PoisonDamageMul - 1.0f);
					break;
				case ConvertableStat::FireDamageMul:
					statToAdd = max(0, stats.FireDamageMul - 1.0f);
					break;
				}
			
				switch (m_mod_stat)
				{
				case ConvertableStat::IceDamageMul:
					stats.IceDamageMul += statToAdd;
					break;
				case ConvertableStat::LightningDamageMul:
					stats.LightningDamageMul += statToAdd;
					break;
				case ConvertableStat::PoisonDamageMul:
					stats.PoisonDamageMul += statToAdd;
					break;
				case ConvertableStat::FireDamageMul:
					stats.FireDamageMul += statToAdd;
					break;
				}
				stats.PhysicalDamageMul = 1;
			}
		}
	}
}