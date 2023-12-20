#include "pch.hpp"

#include "spell.hpp"

i16 Spell::level() { return MEMBER<i16>(0x28); }

float Spell::readyTime() { return MEMBER<float>(0x30); }

// SpellInput *Spell::spellInput() { return MEMBER<SpellInput *>(0x128); }
//
uptr Spell::spell_info() { return MEMBER<uptr>(0x130); }
//
// void SpellInput::SetCasterHandle(int32_t index) { *pMEMBER<int32_t>(0x10) = index; }
//
// void SpellInput::SetTargetHandle(int32_t index) { *pMEMBER<int32_t>(0x14) = index; }
//
// void SpellInput::SetStartPos(FLOAT3 pos) { *pMEMBER<FLOAT3>(0x18) = pos; }
//
// void SpellInput::SetEndPos(FLOAT3 pos) { *pMEMBER<FLOAT3>(0x24) = pos; }
//
// void SpellInput::SetClickedPos(FLOAT3 pos) { *pMEMBER<FLOAT3>(0x30) = pos; }
//
// void SpellInput::SetUnkPos(FLOAT3 pos) { *pMEMBER<FLOAT3>(0x3C) = pos; }

i32 SpellCast::type() { return MEMBER<i32>(0x10); }

i32 SpellCast::slot() { return MEMBER<i32>(0x11C); }

std::string SpellCast::name() { return Read<RiotString16>(Read<uintptr_t>(this) + 0x28).str(); }

bool SpellCast::is_attack() { return MEMBER<bool>(0x112) || MEMBER<bool>(0x113) || MEMBER<bool>(0x114); }

bool SpellCast::is_attack_reset() {
  static constexpr auto reset_attack_spells = std::to_array<hash_type>(
    { FNV("RengarQ")/*ʨ�ӹ�Q*/,FNV("VolibearQAttack")/*����QA*/,FNV("VolibearQ")/*����Q*/,FNV("ApheliosInfernumQ")/*ӫ��Q*/,FNV("AsheQ")/*����Q*/,
      FNV("CamilleQ")/*���ܶ�Q*/,FNV("DariusNoxianTacticsONH")/*ŵ��W*/,FNV("JaxW")/*����W*/,FNV("KayleE")/*��ʹE*/,FNV("LucianE")/*¬����E*/,FNV("SettQ")/*ɪ��Q*/,
      FNV("SivirW")/*������W*/,FNV("VayneTumble")/*VN Q*/,FNV("KindredQ")/*ǧ��Q*/,FNV("AatroxE")/*��ħE*/,FNV("KatarinaE")/*����E*/,FNV("FizzW")/*С����W*/,
      FNV("TalonQAttack")/*�е���QA*/,FNV("TalonQDashAttack")/*�е�ԶQA*/,FNV("XinZhaoQ")/*�°�Q*/,FNV("GarenQ")/*����Q*/,FNV("RivenTriCleave")/*����Q*/,
      FNV("IllaoiW")/*������W*/,FNV("RenektonPreExecute")/*����W*/,FNV("SylasQ")/*����˹Q*/,FNV("SylasW")/*����˹W*/,FNV("SylasE")/*����˹E*/,
      FNV("SylasE2")/*����˹E2*/,FNV("SylasR")/*����˹R*/,FNV("TrundleTrollSmash")/*��ħQ*/,FNV("BriarQ")/*ǾޱQ*/,FNV("Takedown")/*��Ů����̬Q*/,
      FNV("OlafFrenziedStrikes")/*������W*/,FNV("GwenE")/*����E*/,FNV("ShyvanaDoubleAttackDragon")/*��Ů����̬Q*/,FNV("ShyvanaDoubleAttack")/*��Ů����̬Q*/,
      FNV("YorickQ")/*��Ĺ��Q*/,FNV("KSanteQ")/*�ڸ�Q*/,FNV("KSanteQ3")/*�ڸ�Q3*/,FNV("KSanteEAllyDash")/*�ڸ�E*/,FNV("CaitlynWSnare")/*Ů��W���ȵ�*/,
      FNV("ViE")/*ε E*/,FNV("ViegoW")/*�ư���W*/,FNV("MonkeyKingDoubleAttack")/*����Q*/,FNV("CamilleQ2")/*���ܶ�Q2*/,FNV("Obduracy")/*ʯͷ��W*/,
      FNV("RellW_MountUp")/*�Ƕ�����̬W*/,FNV("NasusQ")/*��ͷQ*/,FNV("EkkoE")/*����E*/,FNV("NautilusPiercingGaze")/*̩̹W*/,FNV("ZacQ")/*����Q*/,
      FNV("LeonaShieldOfDaybreak")/*���Q*/,FNV("LeonaShieldOfDaybreakAttack")/*���QA*/,FNV("Meditate")/*��ʥW*/,FNV("FioraE")/*����E*/,FNV("VorpalSpikes")/*�����E*/,
      FNV("NetherBlade")/*������W*/,FNV("KaisaR")/*��ɯR*/,FNV("PowerFist")/*������E*/,FNV("EliseSpiderW")/*֩������̬W*/,FNV("ZeriE")/*����E*/,FNV("DrMundoE")/*�ɶ�E*/, }
  );
  return std::ranges::contains(reset_attack_spells, FNV(name()));
}
