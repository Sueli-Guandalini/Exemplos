<?php
include "classCarro.php";
include "cabecalho.php";
?>
Objetos "Carro" instanciados no sistema: <br />

<?php
	foreach($_SESSION["carro"] as $c){
		echo "
			Cor: <span style='color:$c->cor'>$c->cor</span><br />
			Quantidade portas: $c->qtd_porta <br />
			Velocidade Máxima: $c->velocidade_maxima <br />
			Velocidade Atual: $c->velocidade_atual
			<hr />";
	}
?>
</body>
</html>
		