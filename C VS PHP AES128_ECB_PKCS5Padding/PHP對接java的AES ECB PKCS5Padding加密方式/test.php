<?php
	/**
     * request body加密
     * @param array $content 投保人的信息
     * @return string
     */
    function hetai_encrypt($content) {
        
        // 方案七
        print_r("\r\n");
        vendor('encrypt.Security') or die("方案7引入失败");
        $sec = new Security();
        $string = $content;
        $sec_res = $sec->encrypt($string, base64_decode("eeSvvVtUDLi5lTBHDjCeFw=="));
        $sec_res = strToHex($sec_res);// 结果转16进制并转成大写
        // 这里做了好几次的转换
        // 只是为了迎合出来我需要的结果而已
        // 根据自己的加密要求来定
        $encrypt_upper = strToHex(base64_decode(hexToStr($sec_res)));
        var_dump("\r\n方案7加密的结果\r\n" . $encrypt_upper);
        // 解密
        $sec_res_lower = strtolower($sec_res);// 转小写
        $sec_res_lower_tostr = hexToStr($sec_res);// 16进制转成string
        $sec_dec = $sec->decrypt($sec_res_lower_tostr, base64_decode("eeSvvVtUDLi5lTBHDjCeFw=="));
        var_dump("\r\n方案7解密的结果\r\n" . $sec_dec);
        return $encrypt_upper;
        
    }
?>