class CfgPatches
{
    class QuickFlagPole
    {
        requiredAddons[]=
        {
            
        };
    };
};

class CfgMods
{
    class QuickFlagPole
    {
        name = "QuickFlagPole";
        type = "mod";

        class defs
        {
            class worldScriptModule
            {
                value = "";
                files[] = {"QuickFlagPole\4_World"};
            };
            class missionScriptModule
            {
                value = "";
                files[] = {"QuickFlagPole\5_Mission"};
            };
        };
    };
};