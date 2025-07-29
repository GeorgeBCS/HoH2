<unit layer="-1">
	<behavior class="DangerAreaBehaviorP">
		<int name="freq">500</int>
		<int name="ttl">4000</int>
		<string name="sound-loop">event:/sfx/player/classes/paladin/blessed_strike/blessed_strike_fire_loop</string>
		
		<array name="effects">
			<dict>
				<string name="intensity-mul-bind">fire-dmg-mul</string>
			</dict>
			<dict>
				<string name="class">Damage</string>
				<string name="fire-bind">strike-dmg</string>
				<bool name="true-strike">true</bool>
			</dict>
			<dict>
				<string name="class">PlaySound</string>
				<string name="sound">event:/sfx/player/classes/paladin/blessed_strike/blessed_strike_fire_hit</string>
			</dict>
		</array>

		<dict name="effect-params">
		</dict>
	</behavior>
	
	<scenes>
		<scene>
			<collision static="false">
				<circle sensor="true" aim-through="true" radius="RADIUS" />
			</collision>
			<effect delay="500" src="players/paladin/effects/judgement_fire.effect?radius=RADIUS" />
			<effect src="players/paladin/effects/judgement_fire_start.effect?radius=RADIUS" />
		</scene>
	</scenes>
</unit>