<!DOCTYPE html>
<html lang="pt-BR">
	<head>
		<meta charset="utf-8">
		<title>Barbearia - Agenda</title>
		<link rel="stylesheet" href="estilos.css">
	</head>
	<body>
		<div class="container">
			
			<?php
				include "funcoes.inc";
				include "cabecalho.inc";
				include "menu.inc";
				if(empty($_POST)){
					include "form_agenda.inc";
				}else{
					ler_dados_agenda();
				}
				include "rodape.inc";
			?>	
		</div>
	</body>
</html>