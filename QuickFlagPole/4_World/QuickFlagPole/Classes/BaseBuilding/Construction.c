modded class Construction {

    void QuickBuildPartServer( notnull Man player, string part_name, int action_id ) {
		
        string damage_zone;
		if (DamageSystem.GetDamageZoneFromComponentName(GetParent(),part_name,damage_zone))
		{
			GetParent().SetHealthMax(damage_zone);
		}
		
		//on action
		TakeMaterialsServer( part_name );

		//destroy build collision check trigger
		DestroyCollisionTrigger();

        GetParent().OnPartBuiltServer( player, part_name, action_id );
    }
}