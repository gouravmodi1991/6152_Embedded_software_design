#ifndef IMG_CONV_9X9_I8_C8S_C_H
#define IMG_CONV_9X9_I8_C8S_C_H 1

/* ======================================================================== */
/*  NAME                                                                    */
/*      IMG_conv_5x5_i8_c8s_cn                                              */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*          void IMG_conv_5x5_i8_c8s_cn                                     */
/*          (                                                               */
/*              const unsigned char  *restrict   imgin_ptr,                 */
/*                    unsigned char  *restrict  imgout_ptr,                 */
/*                             short                 width,                 */
/*                             short                 pitch,                 */
/*              const          char  *restrict    mask_ptr,                 */
/*                             short                 shift                  */
/*          )                                                               */
/*                                                                          */
/*      imgin_ptr :   pointer to an input  array of 8 bit pixels            */
/*      imgout_ptr:   pointer to an output array of 8 bit pixels            */
/*      pitch     :   No. of columns in the Input Image.                    */
/*      width     :   No. of output pixels to be calculated.                */
/*      mask_ptr  :   pointer to 8 bit filter mask.                         */
/*      shift     :   user specified shift amount                           */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The convolution kernel accepts five rows of 'pitch' input pixels    */
/*      and produces one row of 'width' output pixels using the input       */
/*      mask of 5 by 5. This convolution performs a point by point mult-    */
/*      iplication of 5 by 5 mask with the input image. The result of 25    */
/*      multiplications are then summed together to produce a 32-bit conv-  */
/*      olution intermediate sum. The user defined shift value is used to   */
/*      shift this convolution sum, down to the byte range and store in an  */
/*      output array. The result being stored is also range limited between */
/*      0 to 255 and will be saturated accordingly. The mask is moved one   */
/*      column at a time, advancing the mask over the entire image until    */
/*      the entire 'width' is covered. The masks are provided as  8-bit     */
/*      signed values. The input image pixels are provided as 8-bit uns-    */
/*      igned pixels and the output pixels will be in 8-bit unsigned.       */
/*                                                                          */
/*      The natural C implementation has no restrictions. The Optimized     */
/*      and IntrinsiC codes has restrictions as noted in the ASSUMPTIONS    */
/*      below.                                                              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      1. width:       'width' >= 4 and multiple of 4.                     */
/*      2. pitch:       'pitch' >= 'width'                                  */
/*      3. Output array should be word-aligned.                             */
/*      4. No restrictions on alignment on input data and mask              */
/*      5. Input and Output arrays should not overlap.                      */
/*                                                                          */
/* ======================================================================== */

void IMG_conv_9x9_i8_c8s_cn(
    const unsigned char *restrict  imgin_ptr,
    unsigned char       *restrict imgout_ptr,
    short                              width,
    short                              pitch,
    const char          *restrict   mask_ptr,
    short                              shift
);

#endif

/* ======================================================================== */
/*  End of file:  IMG_conv_5x5_i8_c8s_c.h                                   */
/* ======================================================================== */


