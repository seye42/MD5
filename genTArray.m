% Build MD5 table of T values as a C constant global array (64 elements, 256 B)
% Values are based on "Oppliger, Rolf. Contemporary cryptography. Artech House, 2011.", section
% 4.3.2.

%% generate the table
i = 1:64;
T = floor(2^32 * abs(sin(i)));

%% display it C syntax
printf("const uint32_t T[64] = {0x%08X, 0x%08X, 0x%08X, 0x%08X,\n", T(1:4));
for idx = 1:14
  printf("                        0x%08X, 0x%08X, 0x%08X, 0x%08X,\n", T(idx * 4 + 1:(idx + 1) * 4));
end
printf("                        0x%08X, 0x%08X, 0x%08X, 0x%08X};\n", T(61:64));
