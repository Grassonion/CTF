<html>
   
   <head>
      <title>The bubbling cauldron</title>
	<!-- Stop peeking around will ya-->      
   </head>
	
<body>

	<?php
	    $msg = "";
	    if (isset($_COOKIE['tbc-session-id'])) {
		if ($_COOKIE['tbc-session-id'] == 'c4ca4238a0b923820dcc509a6f75849b'){
		    $msg = 'BTH_CTF{H3re_4T_Th3_C4Ldr0N_wE_C0uNT_FR0M_0N3}';
		    $line ="Welcome in grandmaster! No need to worry about safety - we have intercepted your secret telepathically.";
		}else{
			$line ="Welcome in oldtimer! No need to worry about safety - we have intercepted your secret telepathically.";
		}
	    }else{
		setcookie('tbc-session-id',md5(rand(2,10)));
		$line ="Welcome in newtimer! No need to worry about safety - we have intercepted your secret telepathically.";
	    }



	?>  
		<h2><?php echo $line;?></h2> 
            <h4><?php echo $msg; ?></h4>
<img src="cauldron.png" alt="BBig image is bigg">
			
     <!-- I said STOP PEEKING AROUND--> 
   </body>
</html>
