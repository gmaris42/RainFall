undefined4 main(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  char *pcVar5;
  byte *pbVar6;
  bool bVar7;
  undefined uVar8;
  undefined uVar9;
  bool bVar10;
  undefined uVar11;
  byte bVar12;
  byte local_90 [5];
  char local_8b [2];
  undefined auStack137 [125];
  
  bVar12 = 0;
  do {
    printf("%p, %p \n",auth,service);
    iVar2 = fgets(local_90,0x80,stdin);
    bVar7 = false;
    bVar10 = iVar2 == 0;
    if (bVar10) {
      return 0;
    }
    iVar2 = 5;
    pbVar4 = local_90;
    pbVar6 = (byte *)"auth ";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar7 = *pbVar4 < *pbVar6;
      bVar10 = *pbVar4 == *pbVar6;
      pbVar4 = pbVar4 + (uint)bVar12 * -2 + 1;
      pbVar6 = pbVar6 + (uint)bVar12 * -2 + 1;
    } while (bVar10);
    uVar8 = 0;
    uVar11 = (!bVar7 && !bVar10) == bVar7;
    if ((bool)uVar11) {
      auth = (undefined4 *)malloc(4);
      *auth = 0;
      uVar3 = 0xffffffff;
      pcVar5 = local_8b;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + (uint)bVar12 * -2 + 1;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3 - 1;
      uVar8 = uVar3 < 0x1e;
      uVar11 = uVar3 == 0x1e;
      if (uVar3 < 0x1f) {
        strcpy(auth,local_8b);
      }
    }
    iVar2 = 5;
    pbVar4 = local_90;
    pbVar6 = (byte *)"reset";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      uVar8 = *pbVar4 < *pbVar6;
      uVar11 = *pbVar4 == *pbVar6;
      pbVar4 = pbVar4 + (uint)bVar12 * -2 + 1;
      pbVar6 = pbVar6 + (uint)bVar12 * -2 + 1;
    } while ((bool)uVar11);
    uVar9 = 0;
    uVar8 = (!(bool)uVar8 && !(bool)uVar11) == (bool)uVar8;
    if ((bool)uVar8) {
      free(auth);
    }
    iVar2 = 6;
    pbVar4 = local_90;
    pbVar6 = (byte *)"service";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      uVar9 = *pbVar4 < *pbVar6;
      uVar8 = *pbVar4 == *pbVar6;
      pbVar4 = pbVar4 + (uint)bVar12 * -2 + 1;
      pbVar6 = pbVar6 + (uint)bVar12 * -2 + 1;
    } while ((bool)uVar8);
    uVar11 = 0;
    uVar8 = (!(bool)uVar9 && !(bool)uVar8) == (bool)uVar9;
    if ((bool)uVar8) {
      uVar11 = (byte *)0xfffffff8 < local_90;
      uVar8 = auStack137 == (undefined *)0x0;
      service = strdup(auStack137);
    }
    iVar2 = 5;
    pbVar4 = local_90;
    pbVar6 = (byte *)"login";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      uVar11 = *pbVar4 < *pbVar6;
      uVar8 = *pbVar4 == *pbVar6;
      pbVar4 = pbVar4 + (uint)bVar12 * -2 + 1;
      pbVar6 = pbVar6 + (uint)bVar12 * -2 + 1;
    } while ((bool)uVar8);
    if ((!(bool)uVar11 && !(bool)uVar8) == (bool)uVar11) {
      if (auth[8] == 0) {
        fwrite("Password:\n",1,10,stdout);
      }
      else {
        system("/bin/sh");
      }
    }
  } while( true );
}