<unit>
	<behavior class="BombBehavior">
		<int name="delay">530</int>

		<array name="actions">
			<dict>
				<string name="class">PlaySound</string>
				<string name="sound">event:/sfx/player/classes/paladin/judgement/judgement_impact</string>
			</dict>
			<dict>
				<string name="class">SpawnEffect</string>
				<string name="effect">players/paladin/effects/judgement_blast_impact.effect</string>
			</dict>
			<dict>
				<string name="class">Explode</string>
				<int name="min-radius">6</int>
				<int name="radius">32</int>
				<int name="dist-scaling">1000</int>
				<array name="effects">
					<dict>
						<string name="class">Damage</string>
						<string name="physical-bind">judgement-dmg</string>
					</dict>
				</array>
			</dict>
%if LIGHTNING
			<dict>
				<string name="class">ChainAction</string>
				<array name="links">
					<dict>
						<string name="class">ChainActionAreaCircleLink</string>
						<int name="radius">64</int>
						<bool name="shoot-from-owner">false</bool>
						<bool name="only-show-shoot-fx-on-hit">true</bool>
						<!-- <int name="max-hits">1</int> -->
						<string name="shoot-fx">effects/generic/raycast/paladin_lightning_beam_1.effect</string>

						<array name="effects">
							<dict>
								<string name="intensity-mul-bind">lightning-dmg-mul</string>
							</dict>
							<dict>
								<string name="class">Damage</string>
								<string name="lightning-bind">judgement-dmg</string>
							</dict>
							<dict>
								<string name="class">PlaySound</string>
								<string name="sound">event:/sfx/player/classes/paladin/judgement/judgement_lightning</string>
							</dict>
						</array>
					</dict>
				</array>
			</dict>
%endif

%if SHACKLES
			<dict>
				<string name="class">ChainAction</string>
				<array name="links">
					<dict>
						<string name="class">ChainActionAreaCircleLink</string>
						<int name="radius">32</int>
						<bool name="shoot-from-owner">false</bool>
						<bool name="only-show-shoot-fx-on-hit">true</bool>
						<string name="shoot-fx">players/paladin/effects/judgement_shackles.effect</string>

						<array name="effects">
							<dict>
								<bool name="only-actors">true</bool>
							</dict>
							<dict>
								<string name="class">ApplyBuff</string>
								<string name="buff-bind">shackles-buff</string>
							</dict>
						</array>
					</dict>
				</array>
			</dict>
%endif
		</array>
	</behavior>
	<scenes	default="default">
		<scene name="default">
		</scene>
	</scenes>
</unit>