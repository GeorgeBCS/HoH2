namespace Modifiers
{				
	class StatConvert : StatModifier, IHandedStatModifier
	{

		ConvertableStat m_orig_stat;
		ConvertableStat m_mod_stat;
		float m_mul;
		void SetRole(Role r) override { m_role = r; }
		Role m_role;
		vec2 m_chance;
		vec2 m_attackCritDmg;

		StatConvert(UnitPtr unit, SValue& params)
		{
			super(unit, params);
			
			m_orig_stat = ParseStat(GetParamString(unit, params, "originatingStat", true));
			m_mod_stat = ParseStat(GetParamString(unit, params, "modifiedStat", true));
			m_mul = GetParamFloat(unit, params, "mul", true);
			
			Ordering = int(ModifierOrdering::Post) + 20;
		}
		
		void Modify(PlayerRecord@ player, PlayerStats@ stats, float intensity) override
		{
			float statToAdd = 1.0f;
			
			{
				switch (m_orig_stat)
				{				
				case ConvertableStat::SpellCritChance:
					statToAdd = max(0, stats.SpellCritChance) * m_mul;
					break;
				case ConvertableStat::SpellCritDamage:
					statToAdd = max(0, stats.SpellCritDamage - 1.5f) * m_mul;
					break;
				case ConvertableStat::IceDamageMul:
					statToAdd = max(0, stats.IceDamageMul - 1.0f) * m_mul;
					break;
				case ConvertableStat::LightningDamageMul:
					statToAdd = max(0, stats.LightningDamageMul - 1.0f) * m_mul;
					break;
				case ConvertableStat::PoisonDamageMul:
					statToAdd = max(0, stats.PoisonDamageMul - 1.0f) * m_mul;
					break;
				case ConvertableStat::FireDamageMul:
					statToAdd = max(0, stats.FireDamageMul - 1.0f) * m_mul;
					break;
				}
			
				switch (m_mod_stat)
				{
				case ConvertableStat::MainHandCritChance:
					if (m_role != Role::MainHand)
					{
						stats.OffHand.CritChance = 1-(1-stats.OffHand.CritChance)*(1-statToAdd);
					}
					stats.MainHand.CritChance = 1-(1-stats.MainHand.CritChance)*(1-statToAdd);
					break;
				case ConvertableStat::MainHandCritDamage:
					if (m_role != Role::MainHand)
					{
						stats.OffHand.CritDamage += statToAdd;
					}
					stats.MainHand.CritDamage += statToAdd;
					break;
				case ConvertableStat::OffHandCritChance:
					stats.OffHand.CritChance = 1-(1-stats.OffHand.CritChance)*(1-statToAdd);
					break;
				case ConvertableStat::OffHandCritDamage:
					stats.OffHand.CritDamage += statToAdd;
					break;
				case ConvertableStat::SpellCritChance:
					stats.SpellCritChance = 1-(1-stats.OffHand.CritChance)*(1-statToAdd);
					break;
				case ConvertableStat::SpellCritDamage:
					stats.SpellCritDamage += statToAdd;
					break;
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
			}
		}
	}
}