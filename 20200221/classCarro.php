<?php
	
	class Carro{
		//Lista de Atributos
		private $cor;
		private $qtd_porta;
		private $velocidade_maxima;
		private $velocidade_atual;
		
		public function __construct($c,$q,$v){
			$this->cor = $c;
			$this->qtd_porta = $q;
			$this->velocidade_maxima = $v;
			$this->velocidade_atual = 0;
		}
		
		public function get_cor(){
			return($this->cor);
		}
		
		public function get_qtd_porta(){
			return($this->qtd_porta);
		}
		
		public function get_velocidade_maxima(){
			return($this->velocidade_maxima);
		}
		
		public function get_velocidade_atual(){
			return($this->velocidade_atual);
		}
		
		
		//lista de Métodos
		public function acelerar($valor_aceleracao, $tempo){
			$this->velocidade_atual = 
				$this->velocidade_atual + $valor_aceleracao*$tempo;
		}
		public function frear($valor_frenagem, $tempo){
			$this->velocidade_atual = 
				$this->velocidade_atual - $valor_frenagem*$tempo;
		}
		public function virar($lado){
			//implementacao
		}
		
		
	}
?>