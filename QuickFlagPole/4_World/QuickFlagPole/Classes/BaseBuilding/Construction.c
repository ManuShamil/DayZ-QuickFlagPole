modded class Construction {

    void QuickBuildPartServer( notnull Man player, string part_name, int action_id ) {

        GetParent().OnQuickPartBuiltServer( player, part_name, action_id );
    }
}