% build MD5 table of 64 T values
% based on section 4.3.2 of Oppliger's Contemporary Cryptography, Second Edition

%% generate the table
i = 1:64;
T = floor(2^32 * abs(sin(i)));

%% display it in a pasteable form as a static C array
printf("const uint32_t T[64] = {0x%08X, 0x%08X, 0x%08X, 0x%08X,\n", T(1:4));
for idx = 1:14
  printf("                        0x%08X, 0x%08X, 0x%08X, 0x%08X,\n",
         T(idx * 4 + 1:(idx + 1) * 4));
end
printf("                        0x%08X, 0x%08X, 0x%08X, 0x%08X};\n", T(61:64));
