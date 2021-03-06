/************************************************************************************
    Copyright (C) 2005-2008 Assefaw H. Gebremedhin, Arijit Tarafdar, Duc Nguyen,
    Alex Pothen

    This file is part of ColPack.

    ColPack is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ColPack is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with ColPack.  If not, see <http://www.gnu.org/licenses/>.
************************************************************************************/

#include "ColPackHeaders.h"

using namespace std;

namespace ColPack
{
	//Virtual Function 2102:3102
	void BipartiteGraphCore::Clear()
	{
		m_i_MaximumLeftVertexDegree = _UNKNOWN;
		m_i_MaximumRightVertexDegree = _UNKNOWN;
		m_i_MaximumVertexDegree = _UNKNOWN;

		m_i_MinimumLeftVertexDegree = _UNKNOWN;
		m_i_MinimumRightVertexDegree = _UNKNOWN;
		m_i_MinimumVertexDegree = _UNKNOWN;

		m_d_AverageLeftVertexDegree = _UNKNOWN;
		m_d_AverageRightVertexDegree = _UNKNOWN;
		m_d_AverageVertexDegree = _UNKNOWN;

		m_s_InputFile.clear();
	
		m_vi_LeftVertices.clear();
		m_vi_RightVertices.clear();

		m_vi_Edges.clear();

		m_mimi2_VertexEdgeMap.clear();

	}
	
	//Public Function 2103:3103
	string BipartiteGraphCore::GetInputFile()
	{
		return(m_s_InputFile);
	}


	//Public Function 2104:3104
	void BipartiteGraphCore::GetRowVertices(vector<int> &output)
	{
		output = (m_vi_LeftVertices);
	}
	
	void BipartiteGraphCore::GetLeftVertices(vector<int> &output)
	{
		output = (m_vi_LeftVertices);
	}
	
	//Public Function 2105:3105
	void BipartiteGraphCore::GetColumnVertices(vector<int> &output)
	{
		output = (m_vi_RightVertices);
	}
	
	void BipartiteGraphCore::GetRightVertices(vector<int> &output)
	{
		output = (m_vi_RightVertices);
	}
	
	unsigned int BipartiteGraphCore::GetRowVertices(unsigned int** ip2_RowVertex)
	{
		(*ip2_RowVertex) = new unsigned int[m_vi_LeftVertices.size()];
		for(unsigned int i=0; i < m_vi_LeftVertices.size(); i++) {
			(*ip2_RowVertex)[i] = m_vi_LeftVertices[i];
		}
		return m_vi_LeftVertices.size();
	}
	
	unsigned int BipartiteGraphCore::GetColumnIndices(unsigned int** ip2_ColumnIndex)
	{
		unsigned int ui_UpperBound = m_vi_LeftVertices[m_vi_LeftVertices.size() - 1];
		(*ip2_ColumnIndex) = new unsigned int[ui_UpperBound];
		for(unsigned int i=0; i < ui_UpperBound; i++) {
			(*ip2_ColumnIndex)[i] = m_vi_Edges[i];
		}
		return ui_UpperBound;
	}
	
	//Public Function 2106:3106
	void BipartiteGraphCore::GetEdges(vector<int> &output)
	{
		output = (m_vi_Edges);
	}
	
	//Public Function 2107:3107
	void BipartiteGraphCore::GetVertexEdgeMap(map< int, map<int, int> > &output)
	{
		output = (m_mimi2_VertexEdgeMap);
	}

	
	//Public Function 2108:3108
	int BipartiteGraphCore::GetRowVertexCount()
	{
		return(STEP_DOWN(m_vi_LeftVertices.size()));
	}

	int BipartiteGraphCore::GetLeftVertexCount()
	{
		return(STEP_DOWN(m_vi_LeftVertices.size()));
	}

	
	//Public Function 2109:3109
	int BipartiteGraphCore::GetColumnVertexCount()
	{
		return(STEP_DOWN(m_vi_RightVertices.size()));
	}

	int BipartiteGraphCore::GetRightVertexCount()
	{
		return(STEP_DOWN(m_vi_RightVertices.size()));
	}

	
	//Public Function 2110:3110
	int BipartiteGraphCore::GetEdgeCount()
	{
		return(m_vi_Edges.size()/2);
	}

	
	//Public Function 2111:3111
	int BipartiteGraphCore::GetMaximumRowVertexDegree()
	{
		return(m_i_MaximumLeftVertexDegree);
	}

	
	//Public Function 2112:3112
	int BipartiteGraphCore::GetMaximumColumnVertexDegree()
	{
		return(m_i_MaximumRightVertexDegree);
	}

	
	//Public Function 2113:3113
	int BipartiteGraphCore::GetMaximumVertexDegree()
	{
		return(m_i_MaximumVertexDegree);
	}

	
	//Public Function 2114:3114
	int BipartiteGraphCore::GetMinimumRowVertexDegree()
	{
		return(m_i_MinimumLeftVertexDegree);
	}

	
	//Public Function 2115:3115
	int BipartiteGraphCore::GetMinimumColumnVertexDegree()
	{
		return(m_i_MinimumRightVertexDegree);
	}

	
	//Public Function 2116:3116
	int BipartiteGraphCore::GetMinimumVertexDegree()
	{
		return(m_i_MinimumVertexDegree);
	}

	
	//Public Function 2117:3117
	double BipartiteGraphCore::GetAverageRowVertexDegree()
	{
		return(m_d_AverageLeftVertexDegree);
	}
	
	//Public Function 2118:3118
	double BipartiteGraphCore::GetAverageColumnVertexDegree()
	{
		return(m_d_AverageRightVertexDegree);
	}
	
	//Public Function 2119:3119
	double BipartiteGraphCore::GetAverageVertexDegree()
	{
		return(m_d_AverageVertexDegree);
	}
}
