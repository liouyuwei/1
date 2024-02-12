bool SpellCast::is_attack_reset() {
  static constexpr auto reset_attack_spells = std::to_array<hash_type>(
    { FNV("RengarQ")/*狮子狗Q*/,FNV("RengarQEmp")/*狮子狗强化Q*/,FNV("VolibearQAttack")/*狗熊QA*/,FNV("VolibearQ")/*狗熊Q*/,FNV("ApheliosInfernumQ")/*荧焰Q*/,FNV("AsheQ")/*寒冰Q*/,
      FNV("CamilleQ")/*卡密尔Q*/,FNV("DariusNoxianTacticsONH")/*诺手W*/,FNV("JaxW")/*武器W*/,FNV("KayleE")/*天使E*/,FNV("LucianE")/*卢锡安E*/,FNV("SettQ")/*瑟提Q*/,
      FNV("SivirW")/*轮子妈W*/,FNV("VayneTumble")/*VN Q*/,FNV("KindredQ")/*千珏Q*/,FNV("AatroxE")/*剑魔E*/,FNV("KatarinaE")/*卡特E*/,FNV("FizzW")/*小鱼人W*/,
      FNV("TalonQAttack")/*男刀近QA*/,FNV("TalonQDashAttack")/*男刀远QA*/,FNV("XinZhaoQ")/*德邦Q*/,FNV("GarenQ")/*德玛Q*/,FNV("RivenTriCleave")/*瑞文Q*/,
      FNV("IllaoiW")/*俄洛依W*/,FNV("RenektonPreExecute")/*鳄鱼W*/,FNV("SylasQ")/*塞拉斯Q*/,FNV("SylasW")/*塞拉斯W*/,FNV("SylasE")/*塞拉斯E*/,
      FNV("SylasE2")/*塞拉斯E2*/,FNV("SylasR")/*塞拉斯R*/,FNV("TrundleTrollSmash")/*巨魔Q*/,FNV("BriarQ")/*蔷薇Q*/,FNV("Takedown")/*豹女兽形态Q*/,
      FNV("OlafFrenziedStrikes")/*奥拉夫W*/,FNV("GwenE")/*格温E*/,FNV("ShyvanaDoubleAttackDragon")/*龙女龙形态Q*/,FNV("ShyvanaDoubleAttack")/*龙女人形态Q*/,
      FNV("YorickQ")/*掘墓者Q*/,FNV("KSanteQ")/*黑哥Q*/,FNV("KSanteQ3")/*黑哥Q3*/,FNV("KSanteEAllyDash")/*黑哥E*/,FNV("CaitlynWSnare")/*女警W被踩到*/,
      FNV("ViE")/*蔚 E*/,FNV("ViegoW")/*破败王W*/,FNV("MonkeyKingDoubleAttack")/*猴子Q*/,FNV("CamilleQ2")/*卡密尔Q2*/,FNV("Obduracy")/*石头人W*/,
      FNV("RellW_MountUp")/*芮尔人形态W*/,FNV("NasusQ")/*狗头Q*/,FNV("EkkoE")/*艾克E*/,FNV("NautilusPiercingGaze")/*泰坦W*/,FNV("ZacQ")/*扎克Q*/,
      FNV("LeonaShieldOfDaybreak")/*曙光Q*/,FNV("LeonaShieldOfDaybreakAttack")/*曙光QA*/,FNV("Meditate")/*剑圣W*/,FNV("FioraE")/*剑姬E*/,FNV("VorpalSpikes")/*大虫子E*/,
      FNV("NetherBlade")/*卡萨丁W*/,FNV("KaisaR")/*卡莎R*/,FNV("PowerFist")/*机器人E*/,FNV("EliseSpiderW")/*蜘蛛兽形态W*/,FNV("ZeriE")/*泽丽E*/,FNV("DrMundoE")/*蒙多E*/,
      FNV("BlueCardLock")/*蓝牌锁定*/,FNV("RedCardLock")/*红牌锁定*/,FNV("GoldCardLock")/*金牌锁定*/,FNV("SejuaniE2")/*猪妹E*/,FNV("3748Active")/*巨型九头蛇*/,FNV("3152Active")/*推推棒*/ }
  );
  return std::ranges::contains(reset_attack_spells, FNV(name()));
}
