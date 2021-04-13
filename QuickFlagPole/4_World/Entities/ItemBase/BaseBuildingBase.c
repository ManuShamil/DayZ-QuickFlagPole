modded class BaseBuildingBase {
    //CONSTRUCTION EVENTS
	//Build
	void OnQuickPartBuiltServer( notnull Man player, string part_name, int action_id )
	{
		ConstructionPart constrution_part = GetConstruction().GetConstructionPart( part_name );
		
		//check base state
		if ( constrution_part.IsBase() )
		{
			SetBaseState( true );
			
			//spawn kit
			//CreateConstructionKit();
		}
			
		//register constructed parts for synchronization
		RegisterPartForSync( constrution_part.GetId() );
		
		//register action that was performed on part
		RegisterActionForSync( constrution_part.GetId(), action_id );
		
		//synchronize
		SynchronizeBaseState();
		
		//if (GetGame().IsMultiplayer() && GetGame().IsServer())
			SetPartFromSyncData(constrution_part); // server part of sync, client will be synced from SetPartsFromSyncData
		
		//update visuals
		UpdateVisuals();
		
		//reset action sync data
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( ResetActionSyncData, 100, false, this );
	}
}