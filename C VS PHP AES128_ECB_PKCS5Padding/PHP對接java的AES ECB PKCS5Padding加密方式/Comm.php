<?php
	/**
     * 字符串转十六进制
     * @param string $string
     * @return string
     */
    function strToHex($string)
    {
        $hex="";
        for($i=0;$i<strlen($string);$i++)
            $hex.=dechex(ord($string[$i]));
        $hex=strtoupper($hex);
        return $hex;
    }
    
    /**
     * 十六进制转字符串
     * 16进制的转为2进制字符串    
     * @param 十六进制 $hex
     * @return string
     */
    function hexToStr($hex)
    {
        $string="";
        for($i=0;$i<strlen($hex)-1;$i+=2)
            $string.=chr(hexdec($hex[$i].$hex[$i+1]));
        return  $string;
    }
?>