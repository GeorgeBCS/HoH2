namespace Modifiers
{				
	class ConvertStatWeighted : ConvertStat, IHandedStatModifier
	{
		ConvertableStat m_from_single;
		void SetRole(Role r) override { m_role = r; }
		Role m_role;

		ConvertStatWeighted(UnitPtr unit, SValue& params)
		{
			super(unit, params);
			m_from_single = ParseStat(GetParamString(unit, params, "from", true));
			m_mul = GetParamVec2(unit, params, "mul", true);
			Ordering = int(ModifierOrdering::Post) + 20;

		}
		
		void Modify(PlayerRecord@ player, PlayerStats@ stats, float intensity) override
		{
			float statToAdd = 0.0f;
			
			{
				switch (m_from)
				{				
				case ConvertableStat::SpellCritChance:
					statToAdd = max(0, stats.SpellCritChance) * lerp(m_mul, intensity);
					break;
				case ConvertableStat::SpellCritDamage:
					statToAdd = max(0, stats.SpellCritDamage - 1.5f) * lerp(m_mul, intensity);
					break;
				case ConvertableStat::IceDamageMul:
					statToAdd = max(0, stats.IceDamageMul - 1.0f) * lerp(m_mul, intensity);
					break;
				case ConvertableStat::LightningDamageMul:
					statToAdd = max(0, stats.LightningDamageMul - 1.0f) * lerp(m_mul, intensity);
					break;
				case ConvertableStat::PoisonDamageMul:
					statToAdd = max(0, stats.PoisonDamageMul - 1.0f) * lerp(m_mul, intensity);
					break;
				case ConvertableStat::FireDamageMul:
					statToAdd = max(0, stats.FireDamageMul - 1.0f) * lerp(m_mul, intensity);
					break;
				}
			
				switch (m_to)
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