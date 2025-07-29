<unit netsync="position" save="false">
	<behavior class="PlayerOwnedActor">
		<string name="team">player</string>
		<int name="hp">9999</int>
		<string name="type">construct</string>
		<int name="unit-height">22</int>
		<int name="overhead-bossbar-width">16</int>
		<int name="ttl">15000</int>
		
		<bool name="targeting">true</bool>
		<bool name="targetable">false</bool>
		<bool name="no-buffs">true</bool>
		<int name="aggro-range">10000</int>
		<bool name="must-see-target">false</bool>
		<int name="teleport-leash">0</int>

		<dict name="movement">
			<string name="class">PassiveMovement</string>
			<string name="anim-idle">idle</string>
		</dict>
		
		<array name="skills">
			<dict>
				<string name="class">CompositeActorAuraSkill</string>
				<string name="buff-bind">banner-buff</string>
				<bool name="friendly">true</bool>
				<int name="freq">250</int>
				<int name="range">100</int>
			</dict>
%if PROTECTION
			<dict>
				<string name="class">CompositeActorAuraSkill</string>
				<string name="buff-bind">banner-prot-buff</string>
				<bool name="friendly">true</bool>
				<int name="freq">250</int>
				<int name="range">100</int>
			</dict>
%endif
%if ZEAL
			<dict>
				<string name="class">CompositeActorAuraSkill</string>
				<string name="buff-bind">banner-zeal-buff</string>
				<bool name="friendly">true</bool>
				<int name="freq">250</int>
				<int name="range">100</int>
			</dict>
%endif
			<dict>
				<string name="class">CompositeActorTriggeredSkill</string>
				<string name="trigger">OnDeath</string>
				<int name="cooldown">0</int>
				<int name="range">999</int>
				<int name="castpoint">0</int>
				<array name="actions">
					<dict>
						<string name="class">SpawnEffect</string>
						<string name="effect">players/paladin/effects/company_banner_disappear.effect</string>
					</dict>
				</array>
			</dict>
		</array>
				
		<dict name="effect-params">
		</dict>
	</behavior>
	
	<scenes start="idle">
		<scene name="idle">
			<collision static="true">
				<circle offset="0 0" radius="0.5" sensor="true" shoot-through="true" aim-through="true" />
			</collision>
			<effect src="players/paladin/effects/company_banner_appear.effect"/>
			<effect delay="500" src="players/paladin/effects/company_banner.effect"/>

			%//<effect layer="-1" src="effects/generic/other/trap_indicator.effect?radius=100&colorr=1&colorg=1&colorb=1"/>
		</scene>
	</scenes>
</unit>
