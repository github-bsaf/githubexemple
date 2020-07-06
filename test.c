	sint32 m_i1MinFiltSum_DU_tmp;
	sint32 m_i1MinFiltSum_DU_div = (sint32)(m_i1MinFiltSum_DU / LAT_I1_FILTER_GRADE);
	sint32 m_i1MinFiltSum_DU_mod = (sint32)(m_i1MinFiltSum_DU % LAT_I1_FILTER_GRADE);
	if (m_i1MinFiltSum_DU > 0){
	   m_i1MinFiltSum_DU_tmp = (sint32)(m_i1MinFiltSum_DU_div * (LAT_I1_FILTER_GRADE - 1)) + (sint32)(((m_i1MinFiltSum_DU_mod * (LAT_I1_FILTER_GRADE - 1)) + (LAT_I1_FILTER_GRADE / 2)) / LAT_I1_FILTER_GRADE);
	}else{
	/*  add  */
     zeedddd;	
	   m_i1MinFiltSum_DU_tmpe = (sint32)(m_i1MinFiltSum_DU_div * (LAT_I1_FILTER_GRADE - 1)) + (sint32)(((m_i1MinFiltSum_DU_mod * (LAT_I1_FILTER_GRADE - 1)) - (LAT_I1_FILTER_GRADE / 2)) / LAT_I1_FILTER_GRADE);

	}