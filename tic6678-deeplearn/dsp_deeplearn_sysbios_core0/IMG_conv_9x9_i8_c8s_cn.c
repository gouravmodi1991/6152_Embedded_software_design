#pragma CODE_SECTION(IMG_conv_9x9_i8_c8s_cn,   ".text:ansi");
void IMG_conv_9x9_i8_c8s_cn
(
    const unsigned char *restrict  imgin_ptr,
    unsigned char       *restrict imgout_ptr,
    short                              width,
    short                              pitch,
    const char          *restrict   mask_ptr,
    short                              shift
)
{
  int     i,      j,      k;
  int     sum;

  /* Point to the end of the mask to account for rotation */
  const char *mask_rot = &mask_ptr[9*9 - 1];

  for (i=0; i<width; i++) {
    sum = 0;

    for (j=0; j<9; j++) {
      for (k=0; k<9; k++) {
        sum += imgin_ptr[j * pitch + i + k] * mask_rot[-(j * 9 + k)];
      }
    }

    sum           = sum >> shift;
    imgout_ptr[i] = (sum > 255) ? 255 : ((sum < 0) ? 0 : sum);
  }
}

/* ======================================================================== */
/*  End of file:  IMG_conv_5x5_i8_c8s_cn.c                                  */
/* ======================================================================== */                                                                                  
