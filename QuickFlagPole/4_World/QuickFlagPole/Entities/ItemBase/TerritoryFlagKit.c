modded class TerritoryFlagKit
{

    /**
     * Parts of this are reused from DayZ's own TerritoryFlagKit.OnPlacementComplete()
     * What has been added are the 3 lines after "Upgrade parts" and the one line after "Automatically add a default flag"
     * We're not super'ing their function because we need to reuse the totem variable
     */
    override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
    {
        if ( GetGame().IsServer() )
		{
			//Create TerritoryFlag
			TerritoryFlag totem = TerritoryFlag.Cast( GetGame().CreateObjectEx( "TerritoryFlag", GetPosition(), ECE_PLACE_ON_SURFACE ) );

            if (totem) {
                totem.SetPosition( position );
                totem.SetOrientation( orientation );

                // Upgrade parts
                totem.GetConstruction().BuildPartServer( player, "base", AT_BUILD_PART );
                totem.GetConstruction().BuildPartServer( player, "support", AT_BUILD_PART );
                totem.GetConstruction().BuildPartServer( player, "pole", AT_BUILD_PART );
                
                // Automatically add a default flag
                totem.GetInventory().CreateAttachment("Flag_Chernarus");
            }
			
			//make the kit invisible, so it can be destroyed from deploy UA when action ends
			HideAllSelections();
			
			this.Delete();
			
			SetIsDeploySound( true );
		}
    }
}