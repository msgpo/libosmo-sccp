/* SCCP User SAP related routines */

/* (C) 2017 by Harald Welte <laforge@gnumonks.org>
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string.h>
#include <osmocom/core/utils.h>
#include <osmocom/core/prim.h>

#include <osmocom/sigtran/sccp_sap.h>

const struct value_string osmo_scu_prim_names[] = {
	{ OSMO_SCU_PRIM_N_CONNECT,		"N-CONNECT" },
	{ OSMO_SCU_PRIM_N_DATA,			"N-DATA" },
	{ OSMO_SCU_PRIM_N_EXPEDITED_DATA,	"N-EXPEDITED-DATA" },
	{ OSMO_SCU_PRIM_N_DISCONNECT,		"N-DISCONNECT" },
	{ OSMO_SCU_PRIM_N_RESET,		"N-RESET" },
	{ OSMO_SCU_PRIM_N_INFORM,		"N-INFORM" },
	{ OSMO_SCU_PRIM_N_UNITDATA,		"N-UNITDATA" },
	{ OSMO_SCU_PRIM_N_NOTICE,		"N-NOTICE" },
	/* management */
	{ OSMO_SCU_PRIM_N_COORD,		"N-COORD" },
	{ OSMO_SCU_PRIM_N_STATE,		"N-STATE" },
	{ OSMO_SCU_PRIM_N_PCSTATE,		"N-PCSATE" },
	{ 0, NULL }
};

static char prim_name_buf[128];

char *osmo_scu_prim_name(struct osmo_prim_hdr *oph)
{
	const char *name = get_value_string(osmo_scu_prim_names, oph->primitive);

	prim_name_buf[0] = '\0';
	strncpy(prim_name_buf, name, sizeof(prim_name_buf)-1);
	prim_name_buf[sizeof(prim_name_buf)-1] = '\0';
	name = get_value_string(osmo_prim_op_names, oph->operation);
	strncat(prim_name_buf, name, sizeof(prim_name_buf)-strlen(prim_name_buf)-2);

	return prim_name_buf;
}
