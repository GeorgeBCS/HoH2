<unit netsync="none">
	<behavior class="NewProjectile">
		<string name="anim">default</string>
		<float name="speed">1.5</float>
		<int name="ttl">8000</int>
		<int name="penetration">999</int>
		<int name="bounces">0</int>
		<bool name="penetrate-all">false</bool>

		<array name="modifiers">
			<dict>
				<string name="class">Projectile::Speed</string>
				<float name="bounce-speed-mul">0</float>
			</dict>
			<dict>
				<string name="class">Projectile::GroundBouncing</string>
				<int name="period">800</int>
				<int name="height">0</int>
				<bool name="hit-target">false</bool>
				<int name="bounces">0</int>
				<float name="speed-mul">0</float>
				<float name="intensity-mul">0.5</float>

				<array name="effects">
<!-- 					<dict>
						<string name="class">SpawnUnit</string>
						<string name="unit-bind">pillar-unit</string>
						<int name="jitter">0 0</int>
					</dict> -->

					<dict>
						<string name="class">Explode</string>
						<int name="min-radius">4</int>
						<int name="radius">20</int>
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
						<string name="effect">players/paladin/effects/pillar_of_justice_explosion.effect?radius=20&lightning=1</string>
					</dict>
%else
					<dict>
						<string name="class">PlaySound</string>
						<string name="sound">event:/sfx/player/classes/paladin/pillar_of_light/pillar_of_light_impact</string>
					</dict>
					<dict>
						<string name="class">SpawnEffect</string>
						<string name="effect">players/paladin/effects/pillar_of_justice_explosion.effect?radius=20</string>
					</dict>
%endif
				</array>
			</dict>
		</array>

		<array name="destroyed-effects">
%if LIGHTNING
			<dict>
				<string name="class">ShootProjectile</string>
				<string name="projectile-bind">pillar-unit-spawner-3-lightning</string>
			</dict>
			<dict>
				<int name="rot-add">90</int>
			</dict>
			<dict>
				<string name="class">ShootProjectile</string>
				<string name="projectile-bind">pillar-unit-spawner-3-lightning</string>
			</dict>
			<dict>
				<int name="rot-add">90</int>
			</dict>
			<dict>
				<string name="class">ShootProjectile</string>
				<string name="projectile-bind">pillar-unit-spawner-3-lightning</string>
			</dict>
			<dict>
				<int name="rot-add">90</int>
			</dict>
			<dict>
				<string name="class">ShootProjectile</string>
				<string name="projectile-bind">pillar-unit-spawner-3-lightning</string>
			</dict>
%else
			<dict>
				<string name="class">ShootProjectile</string>
				<string name="projectile-bind">pillar-unit-spawner-3</string>
			</dict>
			<dict>
				<int name="rot-add">90</int>
			</dict>
			<dict>
				<string name="class">ShootProjectile</string>
				<string name="projectile-bind">pillar-unit-spawner-3</string>
			</dict>
			<dict>
				<int name="rot-add">90</int>
			</dict>
			<dict>
				<string name="class">ShootProjectile</string>
				<string name="projectile-bind">pillar-unit-spawner-3</string>
			</dict>
			<dict>
				<int name="rot-add">90</int>
			</dict>
			<dict>
				<string name="class">ShootProjectile</string>
				<string name="projectile-bind">pillar-unit-spawner-3</string>
			</dict>
%endif
		</array>

		<dict name="effect-params">
		</dict>
	</behavior>

	<scenes default="default">
		<scene name="default">
			<collision static="false">
				<circle projectile="true" radius="1"/>
			</collision>
%if LIGHTNING
			<effect src="players/paladin/effects/pillar_of_justice.effect?radius=20&lightning=1" />
%else
			<effect src="players/paladin/effects/pillar_of_justice.effect?radius=20" />
%endif
		</scene>
	</scenes>
</unit>