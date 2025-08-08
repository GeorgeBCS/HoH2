<unit layer="0">
	<behavior class="DangerAreaBehaviorP">
		<int name="freq">500</int>
		<string name="ttl-bind">wall-ttl</string>
		<string name="sound-loop">event:/sfx/player/classes/sorcerer/flame_wall/flame_wall_loop</string>
		<!-- <int name="actor-filter">69</int> -->
		<!-- <string name="team-override">player</string> -->
		
		<array name="effects">
			<dict>
				<float name="self-dmg">0</float>
				<float name="team-dmg">0</float>
				<float name="enemy-dmg">1</float>
				<bool name="only-actors">true</bool>
			</dict>
			<dict>
				<string name="class">Damage</string>
				<string name="fire-bind">wall-dmg</string>
				<bool name="true-strike">true</bool>
			</dict>
<!-- 			<dict>
				<string name="class">ApplyBuff</string>
				<string name="buff-bind">wall-debuff</string>
			</dict> -->

			<dict>
				<float name="self-dmg">1</float>
				<float name="team-dmg">1</float>
				<float name="enemy-dmg">0</float>
			</dict>
			<dict>
				<string name="class">ApplyBuff</string>
				<string name="buff">players/sorcerer/stacks_sorcerer.sval:flamewalkercrit</string>
			</dict>
			<dict>
				<float name="self-dmg">1</float>
				<float name="team-dmg">0</float>
				<float name="enemy-dmg">0</float>
			</dict>
			<dict>
				<string name="class">AddStacks</string>
				<bool name="target-self">true</bool>
				<string name="buff">players/sorcerer/stacks_sorcerer.sval:flamewalkercrit</string>
				<int name="stacks">1</int>
			</dict>
		</array>
	</behavior>

	<scenes>
		<scene>
			<collision static="false">
				<circle radius="16" sensor="true" shoot-through="true" aim-through="true" />
			</collision>
			<effect src="players/wizard/effects/wall_fire.effect" />
			<effect layer="-1" src="effects/generic/areas/fire_area_ground_1.effect?radius=16" />
		</scene>
	</scenes>
</unit>