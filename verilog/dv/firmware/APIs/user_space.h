/**
 \file
*/
#ifndef USER_ADDR_SPACE_C_HEADER_FILE
#define USER_ADDR_SPACE_C_HEADER_FILE

inline void USER_writeWord(volatile int data,int offset) __attribute__((always_inline));
inline volatile int USER_readWord(int offset) __attribute__((always_inline));
inline void USER_writeHalfWord(volatile short data,volatile int offset,bool is_first_word) __attribute__((always_inline));
inline volatile short USER_readHalfWord(volatile int offset,bool is_first_word) __attribute__((always_inline));
inline void USER_writeByte(volatile char data,volatile int offset,volatile char byte_num) __attribute__((always_inline));
inline volatile char USER_readByte( volatile int offset,volatile char byte_num) __attribute__((always_inline));

/**
 * Enable communication  between firmware and user project through wishbone 
 * \warning 
 * This necessary when reading or writing are needed between wishbone and user project 
 * if interface isn't enabled no ack would be receive  and the writing or reading command will be stuck
 */
void User_enableIF(){
    reg_wb_enable =1; // for enable writing to reg_debug_1 and reg_debug_2
}


/**
 * Write word (4 bytes) at user address space 32 bit register
 *  
 * @param data  world data to write
 * @param offset the offset of the register to write. Origin at the user project address
 * 
 * \note 
 * Since offset is a word (4 bytes) and address space represent bytes, offset = address /4
 * \n For example if project caravel space are 26 address bit offset = wb_addr_i[25:0]/4
 * 
 * <table>
    <caption id="multi_row"> world memory (4 bytes offset)</caption>
    <tr><th>address<th>offset <th>byte0<th>byte1<th>byte2<th>byte3
    <tr><td>0x0<td>0<td style="background-color:#FED64E">0<td style="background-color:#FED64E">1<td style="background-color:#FED64E">2<td style="background-color:#FED64E">3
    <tr><td>0x4<td>1<td style="background-color:#EDBB99">4<td style="background-color:#EDBB99">5<td style="background-color:#EDBB99">6<td style="background-color:#EDBB99">7
    <tr><td>0x8<td>2<td style="background-color:#FED64E">8<td style="background-color:#FED64E" >9<td style="background-color:#FED64E">10<td style="background-color:#FED64E">11
    <tr><td>0xC<td>3<td style="background-color:#EDBB99">12<td style="background-color:#EDBB99">13<td style="background-color:#EDBB99">14<td style="background-color:#EDBB99">15   </table>

 */


inline void USER_writeWord(volatile int data,int offset){
    *(((volatile int *) USER_SPACE_ADDR)+offset) = data;

}
/**
 * Read  word (4 bytes) at user address space 32 bit register
 *  
 * @param offset the offset of the register to write. Origin at the user project address
 * 
 * \note 
 * Since offset is a word (4 bytes) and address space represent bytes, offset = address /4
 * \n For example if project caravel space are 26 address bit offset = wb_addr_i[25:0]/4
 * 
 *  <table>
    <caption id="multi_row"> world memory (4 bytes offset)</caption>
    <tr><th>address<th>offset <th>byte0<th>byte1<th>byte2<th>byte3
    <tr><td>0x0<td>0<td style="background-color:#FED64E">0<td style="background-color:#FED64E">1<td style="background-color:#FED64E">2<td style="background-color:#FED64E">3
    <tr><td>0x4<td>1<td style="background-color:#EDBB99">4<td style="background-color:#EDBB99">5<td style="background-color:#EDBB99">6<td style="background-color:#EDBB99">7
    <tr><td>0x8<td>2<td style="background-color:#FED64E">8<td style="background-color:#FED64E" >9<td style="background-color:#FED64E">10<td style="background-color:#FED64E">11
    <tr><td>0xC<td>3<td style="background-color:#EDBB99">12<td style="background-color:#EDBB99">13<td style="background-color:#EDBB99">14<td style="background-color:#EDBB99">15   </table>

 */
inline volatile int USER_readWord(int offset){
    return *(((volatile int *) USER_SPACE_ADDR)+offset);
}
/**
 * Write half word (2 bytes) at user address space 32 bit register
 *  
 * @param data  half world data to write
 * @param offset the offset of the register to write. Origin at the user project address
 * @param is_first_word the offset of the register to write. Origin at the user project address
 * 
 * \note 
 * Since offset is a word (4 bytes) and address space represent bytes, offset = address /4
 * \n For example if project caravel space are 26 address bit offset = wb_addr_i[25:0]/4
 * 
 *  <table>
    <caption id="multi_row"> world memory (2byte offset)</caption>
    <tr><th>is first word<th>-<th> 1<th> 1 <th>0<th>0
    <tr><th>address<th>offset <th>byte0<th>byte1<th>byte2<th>byte3
    <tr><td>0x0<td>0<td style="background-color:#FEF5E7">0<td style="background-color:#FEF5E7">1<td style="background-color:#FED64E">2<td style="background-color:#FED64E">3
    <tr><td>0x4<td>1<td style="background-color:#FAD7A0">4<td style="background-color:#FAD7A0">5<td style="background-color:#EDBB99">6<td style="background-color:#EDBB99">7
    <tr><td>0x8<td>2<td style="background-color:#FEF5E7">8<td style="background-color:#FEF5E7" >9<td style="background-color:#FED64E">10<td style="background-color:#FED64E">11
    <tr><td>0xC<td>3<td style="background-color:#FAD7A0">12<td style="background-color:#FAD7A0">13<td style="background-color:#EDBB99">14<td style="background-color:#EDBB99">15   </table>

 */
inline void USER_writeHalfWord(volatile short data,volatile int offset,bool is_first_word){
    volatile int half_word_offset = offset *2 + is_first_word;
    *(((volatile int *) USER_SPACE_ADDR)+half_word_offset) = data;
    
}
/**
 * Read half word (2 bytes) at user address space 32 bit register
 *  
 * @param offset the offset of the register to write. Origin at the user project address
 * @param is_first_word the offset of the register to write. Origin at the user project address
 * 
 * \note 
 * Since offset is a word (4 bytes) and address space represent bytes, offset = address /4
 * \n For example if project caravel space are 26 address bit offset = wb_addr_i[25:0]/4
 * 
 *  <table>
    <caption id="multi_row"> world memory (2byte offset)</caption>
    <tr><th>is first word<th>-<th> 1<th> 1 <th>0<th>0
    <tr><th>address<th>offset <th>byte0<th>byte1<th>byte2<th>byte3
    <tr><td>0x0<td>0<td style="background-color:#FEF5E7">0<td style="background-color:#FEF5E7">1<td style="background-color:#FED64E">2<td style="background-color:#FED64E">3
    <tr><td>0x4<td>1<td style="background-color:#FAD7A0">4<td style="background-color:#FAD7A0">5<td style="background-color:#EDBB99">6<td style="background-color:#EDBB99">7
    <tr><td>0x8<td>2<td style="background-color:#FEF5E7">8<td style="background-color:#FEF5E7" >9<td style="background-color:#FED64E">10<td style="background-color:#FED64E">11
    <tr><td>0xC<td>3<td style="background-color:#FAD7A0">12<td style="background-color:#FAD7A0">13<td style="background-color:#EDBB99">14<td style="background-color:#EDBB99">15   </table>

 */
inline volatile short USER_readHalfWord(volatile int offset,bool is_first_word){
    volatile int half_word_offset = offset *2 + is_first_word;
    return *(((volatile int *) USER_SPACE_ADDR)+half_word_offset);
}
/**
 * Write byte  at user address space 32 bit register
 *  
 * @param data byte data to write
 * @param offset the offset of the register to write. Origin at the user project address
 * @param byte_num number of the in the 4 bytes register (32 bits)
 * 
 * \note 
 * Since offset is a word (4 bytes) and address space represent bytes, offset = address /4
 * \n For example if project caravel space are 26 address bit offset = wb_addr_i[25:0]/4
 * 
 *  <table>
    <caption id="multi_row"> world memory (2byte offset)</caption>
    <tr><th >byte_num<th>-<th> 0 <th >1<th >2<th >3
    <tr><th>address<th>offset <th>byte0<th>byte1<th>byte2<th>byte3
    <tr><td>0x0<td>0<td style="background-color:#FEF5E7">0<td style="background-color:#FAD7A0">1<td style="background-color:#FED64E">2<td style="background-color:#EDBB99">3
    <tr><td>0x4<td>1<td style="background-color:#FED64E">4<td style="background-color:#EDBB99">5<td style="background-color:#FEF5E7">6<td style="background-color:#FAD7A0">7
    <tr><td>0x8<td>2<td style="background-color:#FEF5E7">8<td style="background-color:#FAD7A0" >9<td style="background-color:#FED64E">10<td style="background-color:#EDBB99">11
    <tr><td>0xC<td>3<td style="background-color:#FED64E">12<td style="background-color:#EDBB99">13<td style="background-color:#FEF5E7">14<td style="background-color:#FAD7A0">15   </table>

 */
inline void USER_writeByte(volatile char data,volatile int offset,volatile char byte_num){
    if (byte_num > 3) 
        byte_num =0; 
    volatile int byte_offset = offset *4 + byte_num;
    *(((volatile int *) USER_SPACE_ADDR)+byte_offset) = data;
}
/**
 * Read byte  at user address space 32 bit register
 *  
 * @param offset the offset of the register to write. Origin at the user project address
 * @param byte_num number of the in the 4 bytes register (32 bits)
 * 
 * \note 
 * Since offset is a word (4 bytes) and address space represent bytes, offset = address /4
 * \n For example if project caravel space are 26 address bit offset = wb_addr_i[25:0]/4
 * 
 *  <table>
    <caption id="multi_row"> world memory (2byte offset)</caption>
    <tr><th >byte_num<th>-<th> 0 <th >1<th >2<th >3
    <tr><th>address<th>offset <th>byte0<th>byte1<th>byte2<th>byte3
    <tr><td>0x0<td>0<td style="background-color:#FEF5E7">0<td style="background-color:#FAD7A0">1<td style="background-color:#FED64E">2<td style="background-color:#EDBB99">3
    <tr><td>0x4<td>1<td style="background-color:#FED64E">4<td style="background-color:#EDBB99">5<td style="background-color:#FEF5E7">6<td style="background-color:#FAD7A0">7
    <tr><td>0x8<td>2<td style="background-color:#FEF5E7">8<td style="background-color:#FAD7A0" >9<td style="background-color:#FED64E">10<td style="background-color:#EDBB99">11
    <tr><td>0xC<td>3<td style="background-color:#FED64E">12<td style="background-color:#EDBB99">13<td style="background-color:#FEF5E7">14<td style="background-color:#FAD7A0">15   </table>

 */
volatile char USER_readByte( volatile int offset,volatile char byte_num){
    if (byte_num > 3) 
        byte_num =0; 
    volatile int byte_offset = offset *4 + byte_num;
    return *(((volatile int *) USER_SPACE_ADDR)+byte_offset);
}

#endif // USER_ADDR_SPACE_C_HEADER_FILE
