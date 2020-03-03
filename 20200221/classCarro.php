*/<?php

	class Carro{
		//Lista de atributos
		public $cor;
		public $qtd_porta;
		public $velocidade_maxima;
		public $velocidade_atual;
		
		//Lista de métodos
		public function acelerar($valor_aceleracao, $tempo){
			$this->velocidade_atual =
				$this->velocidade_atual + $valor_aceleracao*$tempo;
		}
		public function frear($valor_frenagem, $tempo){
			$this->velocidade_atual =
				$this->velocidade_atual - $valor_frenagem*$tempo;
		}
		public function virar($lado){
			
		}
	}
	
?>*/

<?php

	class Carro{
		//Lista de atributos
		private $cor;
		private $qtd_porta;
		private $velocidade_maxima;
		private $velocidade_atual;
		
		public function __construct($cor, $qtd_porta, $velocidade_maxima, $velocidade_atual){
		$this->set_cor($cor);
		$this->set_qtd_porta($qtd_porta);
		$this->set_velocidade_maxima($velocidade_maxima);
		$this->set_velocidade_atual ($velocidade_atual);
	}
	
	public function set_cor($valor){
		$this->cor = $valor;
	}
	
	public function set_qtd_porta($valor){
		$this->qtd_porta = $valor;
	}
	
	public function set_velocidade_maxima($valor){
		$this->velocidade_maxima = $valor;
	}
	
	public function set_velocidade_atual($valor){
		$this->velocidade_atual = $valor;
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
	
	//Lista de métodos
		public function acelerar($valor_aceleracao, $tempo){
			$this->velocidade_atual =
				$this->velocidade_atual + $valor_aceleracao*$tempo;
		}
		public function frear($valor_frenagem, $tempo){
			$this->velocidade_atual =
				$this->velocidade_atual - $valor_frenagem*$tempo;
		}
		public function virar($lado){
			
		}
	
	}
?>