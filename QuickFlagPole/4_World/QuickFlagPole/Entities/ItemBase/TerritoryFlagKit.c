modded class TerritoryFlagKit {
		
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" ) {
		if ( GetGame().IsServer() )
		{
			//Create TerritoryFlag
			TerritoryFlag totem = TerritoryFlag.Cast( GetGame().CreateObjectEx( "TerritoryFlag", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			totem.SetPosition( position );
			totem.SetOrientation( orientation );

			// Upgrade parts
			totem.GetConstruction().QuickBuildPartServer( player, "base", AT_BUILD_PART );
			totem.GetConstruction().QuickBuildPartServer( player, "support", AT_BUILD_PART );
			totem.GetConstruction().QuickBuildPartServer( player, "pole", AT_BUILD_PART );
			
			// Automatically add a default flag
			totem.GetInventory().CreateAttachment("Flag_Chernarus");

			totem.AnimateFlag( 0 );
			totem.AddRefresherTime01( 1 );
			
			//make the kit invisible, so it can be destroyed from deploy UA when action ends
			HideAllSelections();

			this.Delete();
			
			SetIsDeploySound( true );

		}
	}

}
