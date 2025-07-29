<unit layer="0">
	<behavior class="BombBehavior">
		<int name="delay">800</int>

		<array name="actions">
			<dict>
				<string name="class">Explode</string>
				<int name="min-radius">6</int>
				<int name="radius">40</int>
				<float name="dist-scaling">1000</float>

				<array name="effects">
					<dict>
						<string name="class">ApplyBuff</string>
						<string name="buff">tweak/buffs/status_effects.sval:blindness</string>
					</dict>
					<dict>
						<string name="class">Damage</string>
						<string name="physical-bind">pillar-dmg</string>
					</dict>
%if LIGHTNING
					<dict>
						<string name="intensity-mul-bind">lightning-mul</string>
					</dict>
					<dict>
						<string name="class">Damage</string>
						<string name="lightning-bind">pillar-dmg</string>
					</dict>
%endif
				</array>
			</dict>
%if LIGHTNING
			<dict>
				<string name="class">PlaySound</string>
				<string name="sound">event:/sfx/player/classes/paladin/pillar_of_light/pillar_of_light_impact_electric</string>
			</dict>
			<dict>
				<string name="class">SpawnEffect</string>
				<string name="effect">players/paladin/effects/pillar_of_justice_explosion.effect?radius=40&lightning=1</string>
			</dict>
%else
			<dict>
				<string name="class">PlaySound</string>
				<string name="sound">event:/sfx/player/classes/paladin/pillar_of_light/pillar_of_light_impact</string>
			</dict>
			<dict>
				<string name="class">SpawnEffect</string>
				<string name="effect">players/paladin/effects/pillar_of_justice_explosion.effect?radius=40</string>
			</dict>
%endif
		</array>
	</behavior>
	
	<scenes>
		<scene>
%if LIGHTNING
			<effect src="players/paladin/effects/pillar_of_justice.effect?radius=40&lightning=1" />
%else
			<effect src="players/paladin/effects/pillar_of_justice.effect?radius=40" />
%endif
		</scene>
	</scenes>
</unit>